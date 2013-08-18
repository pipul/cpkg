#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#include "cmd.h"
#include "package.h"

struct package *pkg_new(const char *path) {
	struct package *pkg;
	char *pos;

	if (strlen(path) >= PATH_MAXLEN)
		return NULL;
	if (!(pos = strstr(path, "/src/"))) {
		// invalid package pathname ...
		return NULL;
	}
	if (!(pkg = calloc(sizeof(*pkg), 1)))
		return NULL;
	INIT_LIST_HEAD(&pkg->subpkgs);
	snprintf(pkg->name, PATH_MAXLEN, "%s", pos + 5);
	slice_init(&pkg->cmdops);
	slice_init(&pkg->aux_source);
	return pkg;
}

void pkg_destroy(struct package *pkg) {
	slice_destroy(&pkg->cmdops);
	slice_destroy(&pkg->aux_source);
	free(pkg);
}


struct package *pkg_make(struct env *ev, char *path) {
	char *srcfile;
	int i;
	struct slice ents;
	struct package *pkg, *child;

	if (!env_check(ev, path)) {
		fprintf(stderr, "env check failed: %s %s\n", ev->srcpath, path);
		exit(-1);
	}
		
	if (!(pkg = pkg_new(path))) {
		fprintf(stderr, "can't create package: %s\n", path);
		exit(-1);
	}
	pkg->env = ev;
	slice_init(&ents);
	path_walk(path, &ents);

	for (i = 0; i < slice_size(&ents); i++) {
		srcfile = slice_get(&ents, i);
		if (!path_isfile(srcfile) && !path_isdir(srcfile))
			goto out;
		if (path_isdir(srcfile)) {
			child = pkg_make(ev, srcfile);
			if (child)
				list_add(&child->child, &pkg->subpkgs);
		out:
			free(srcfile);
			continue;
		}
		slice_append(&pkg->aux_source, srcfile);
	}

	slice_destroy(&ents);
	return pkg;
}


void pkg_makeroot(struct env *env) {
	struct slice ents;
	int i;
	char *subdir;
	struct package *pkg;

	slice_init(&ents);
	path_walk(env->srcpath, &ents);
	
	for (i = 0; i < slice_size(&ents); i++) {
		subdir = slice_get(&ents, i);
		if (!path_isdir(subdir))
			goto out;
		if (pkg = pkg_make(env, subdir))
			list_add(&pkg->child, &env->allpackages);
	out:
		free(subdir);
	}
	slice_destroy(&ents);

	return;
}


static struct package *__pkg_find_current(struct package *pkg, const char *pkg_name) {
	struct package *fpkg, *fpkg2;

	if (strcmp(pkg->name, pkg_name) == 0)
		return pkg;
	if (!strprefix(pkg_name, pkg->name))
		goto out;

	list_for_each_entry(fpkg, &pkg->subpkgs, struct package, child) {
		fpkg2 = __pkg_find_current(fpkg, pkg_name);
		if (fpkg2)
			return fpkg2;
	}
 out:
	return NULL;
}

struct package *pkg_find(const char *pkg_name) {
	struct package *pkg, *fpkg;
	struct env *env;

	list_for_each_entry(env, &env_list, struct env, alllink) {
		list_for_each_entry(pkg, &env->allpackages, struct package, child) {
			fpkg = __pkg_find_current(pkg, pkg_name);
			if (fpkg)
				return fpkg;
		}
	}
	return NULL;
}


void pkg_load_definitions(struct package *pkg) {
	char fullpath[PATH_MAXLEN];
	char buf[BUFFER_MAXLEN];
	char *pos;
	int fd, n, off, len, i;
	struct cmd_ops *cmd;
	struct slice *cmd_args;
	char *args[DEFCMD_MAXARGC];
	struct package *child;

	// first: process child dependence.
	list_for_each_entry(child, &pkg->subpkgs, struct package, child) {
		pkg_load_definitions(child);
	}
	
	snprintf(fullpath, PATH_MAXLEN, "%s/%s/%s",
		 pkg->env->srcpath, pkg->name, DEFCONF_NAME);
	if ((fd = open(fullpath, O_RDONLY)) < 0) {
		fprintf(stderr, "can't load difinitions file: %s\n", fullpath);
		goto default_cmd;
	}
	off = 0;
	while ((n = read(fd, buf + off, BUFFER_MAXLEN - off)) + off > 0) {
		buf[n + off] = '\0';
		strreplace(buf, "\n", '\0', 1);
		len = strsplit(buf, " ", args, DEFCMD_MAXARGC);
		args[len] = NULL;

		if (!(cmd_args = calloc(sizeof(*cmd_args), 1)))
			continue; // todo fix warning...
		slice_init(cmd_args);
		slice_appendn(cmd_args, len, (void **)args);
		slice_append(&pkg->cmdops, cmd_args);

		len = strlen(buf) + 1;
		strncpy(buf, buf + len, BUFFER_MAXLEN - len);
		off = strlen(buf);
	}

 default_cmd:
	// process the default command definitions
	if (!(cmd_args = calloc(sizeof(*cmd_args), 1))) {
		fprintf(stderr, "can't make the default command...\n");
		exit(-1);
	}
	slice_init(cmd_args);
	slice_append(cmd_args, strdup("build"));
	slice_append(&pkg->cmdops, cmd_args);
	
	return;
}


void pkg_process_command(struct package *pkg) {
	struct package *child;
	struct slice *cmd_args;
	int i;
	char *cmd_name;
	struct cmd_ops *cmd;

	// first: build the sub packages.
	list_for_each_entry(child, &pkg->subpkgs, struct package, child) {
		pkg_process_command(child);
	}

	// second: build itself
	for (i = 0; i < slice_size(&pkg->cmdops); i++) {
		cmd_args = slice_get(&pkg->cmdops, i);
		if (slice_size(cmd_args) == 0) {
			fprintf(stderr, "invalid cmd arguments: %s\n", pkg->name);
			exit(-1);
		}
		cmd_name = slice_get(cmd_args, 0);
		cmd = get_cmd_by_name(cmd_name);
		if (!cmd) {
			fprintf(stderr, "command not found: %s\n", cmd_name);
			continue;
		}
		cmd->cmd_process(pkg, slice_size(cmd_args) - 1,
				 (char **)(slice_data(cmd_args) + 1));
	}
	return;
}
