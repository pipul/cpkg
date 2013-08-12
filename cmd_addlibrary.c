#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmd.h"
#include "list.h"

static void addlibrary_process(struct package *pkg, int argc, char **argv) {
	char *pkg_name;
	int i, j;
	char *cmd_name;
	struct slice *cmd_args;
	struct package *impkg;

	if (argc < 1) {
		fprintf(stderr, "too few arguments for to cmd: add_library\n");
		exit(-1);
	}
	// maybe a ring
	//if (pkg->status & PKG_PENDING) {
	//	fprintf(stderr, "the dependence link is a loop: %s\n", pkg->name);
	//	exit(-1);
	//}
	for (i = 0; i < argc; i++) {
		if (!(impkg = pkg_find(argv[i]))) {
			fprintf(stderr, "unknown package: %s\n", argv[i]);
			exit(-1);
		}
		if (!(impkg->status & PKG_DEPENDENCE_DONE)) {
			for (j = 0; j < slice_size(&impkg->cmdops); j++) {
				cmd_args = slice_get(&impkg->cmdops, j);
				if ((cmd_name = slice_get(cmd_args, 0))
				    && (strcmp(cmd_name, "add_library"))) {
					addlibrary_process(impkg,
							   slice_size(&impkg->cmdops) - 1,
							   (char **)slice_data(&impkg->cmdops) + 1);
				}
			}
		}
		slice_merge_from(&pkg->aux_source, &impkg->aux_source);
	}
	return;
}



struct cmd_ops cmd_addlibrary = {
	.name = "add_library",
	.cmd_process = addlibrary_process,
};
