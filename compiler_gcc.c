#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "slice.h"
#include "compiler.h"



static void gcc_compile_package(struct package *pkg) {
	struct slice srcs, objs, *aux_source;
	int i, size, status;
	pid_t pid;
	char *srcfile, *objfile;
	char objpath[PATH_MAXLEN];
	char libpath[PATH_MAXLEN];
	struct stat finfo;
	struct package *child;

	slice_init(&srcs);
	slice_init(&objs);

	// init the gcc compiler
	slice_append(&srcs, "gcc");
	snprintf(objpath, PATH_MAXLEN, "%s/%s", pkg->env->objpath, pkg->name);

	// if the output directory doesn't exist, we create it...
	if (stat(objpath, &finfo) != 0) {
		path_mkdir(objpath, 0755, 1);
	}
	aux_source = &pkg->aux_source;
	for (i = 0; i < slice_size(aux_source); i++) {
		srcfile = slice_get(aux_source, i);
		if (!check_pkg_source(srcfile, lang_c))
			continue;
		slice_append(&srcs, srcfile);
	}
	slice_append(&srcs, "-c");

	fprintf(stdout, "building %s by using compiler: gcc...\n", pkg->name);
	if ((pid = fork()) == 0) {
		chdir(objpath);
		execvp("gcc", (char **)slice_data(&srcs));
	}
	waitpid(pid, &status, 0);

	
	// init the ar
	path_walkfile(objpath, &pkg->objs);

	slice_append(&objs, "ar");
	slice_append(&objs, "rus");
	snprintf(libpath, PATH_MAXLEN, "%s/%s", pkg->env->libpath, pkg->name);
	if (stat(libpath, &finfo) != 0) {
		path_mkdir(libpath, 0755, 1);
	}
	snprintf(libpath, PATH_MAXLEN, "%s/%s/%s.a", pkg->env->libpath,
		 pkg->name, path_base(pkg->name));
	slice_append(&objs, libpath);
	slice_merge_from(&objs, &pkg->objs);
	
	if ((pid = fork()) == 0) {
		chdir(libpath);
		execvp("ar", (char **)slice_data(&objs));
	}
	waitpid(pid, &status, 0);
	
	slice_destroy(&srcs);
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
