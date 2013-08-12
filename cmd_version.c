#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd.h"

static void version_process(struct package *pkg, int argc, char **argv) {
	fprintf(stderr, "checking package version: %s\n", argv[0]);
}


struct cmd_ops cmd_version = {
	.name = "version",
	.cmd_process = version_process,
};
