#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "slice.h"
#include "compiler.h"



static void gcc_compile_package(struct package *pkg) {
	struct slice objs, *aux_source;
	int i, size;
	pid_t pid;
	char *srcfile;
	char fullpath[PATH_MAXLEN];
	struct stat finfo;
	struct package *child;

	list_for_each_entry(child, &pkg->subpkgs, struct package, child) {
		gcc_compile_package(child);
	}

	slice_init(&objs);
	slice_append(&objs, "gcc");
	aux_source = &pkg->aux_source;
	for (i = 0; i < slice_size(aux_source); i++) {
		srcfile = slice_get(aux_source, i);
		if (!check_pkg_source(srcfile, lang_c))
			continue;
		slice_append(&objs, srcfile);
	}
	slice_append(&objs, "-c");
	snprintf(fullpath, PATH_MAXLEN, "%s/%s", pkg->env->objpath, pkg->name);

	// if the output directory doesn't exist, we create it...
	if (stat(fullpath, &finfo) != 0) {
		mkdir(fullpath, 0755);
	}

	if ((pid = fork()) == 0) {
		fprintf(stdout,
			"building %s by using compiler: gcc...\n", pkg->name);
		chdir(fullpath);
		execvp("gcc", (char **)slice_data(&objs));
		exit(0);
	}
	slice_destroy(&objs);
	return;
}







static char *gcc_suffix[] = {
	".c",
};

struct compiler_ops gcc_compiler = {
	.name = "gcc",
	.suffix = gcc_suffix,
	.suffix_len = 1,
	.compile = gcc_compile_package,
};
