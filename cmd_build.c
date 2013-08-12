#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "cmd.h"
#include "compiler.h"

static char *get_file_suffix(const char *filename) {
	return strstr(filename, ".");
}

static void build_process(struct package *pkg, int argc, char **argv) {
	char *srcfile, *suffix;
	int i, j;
	struct slice compilers, *aux_source;
	struct compiler_ops *cpl, *tmp;

	slice_init(&compilers);
	aux_source = &pkg->aux_source;
	for (i = 0; i < slice_size(aux_source); i++) {
		srcfile = slice_get(aux_source, i);
		if (!(suffix = get_file_suffix(srcfile)))
			continue;
		if (!(cpl = get_compiler_by_suffix(suffix)))
			continue;

		tmp = NULL;
		for (j = 0; j < slice_size(&compilers); j++) {
			tmp = slice_get(&compilers, j);
			if (tmp == cpl)
				break;
		}
		if (!tmp)
			slice_append(&compilers, cpl);
	}

	for (i = 0; i < slice_size(&compilers); i++) {
		cpl = slice_get(&compilers, i);
		cpl->compile(pkg);
	}
	slice_destroy(&compilers);

	return;
}


struct cmd_ops cmd_build = {
	.name = "build",
	.cmd_process = build_process,
};
