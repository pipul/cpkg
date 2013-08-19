#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "env.h"
#include "path.h"
#include "compiler.h"

static char *usage = "\n\
cpkg - a large package building system\n\
\n\
Usage:\n\
	cpkg command [arguments]\n\
\n\
The commands are:\n\
	test automatic test package\n\
	build compile packages and dependencies\n\
	check checking the cpkg itself\n\n";


int do_build(int argc, char **argv) {
	struct env env;
	char *dir;
	char wd[PATH_MAXLEN];

	getcwd(wd, PATH_MAXLEN);
	dir = path_dir(wd);
	INIT_LIST_HEAD(&env.allpackages);
	snprintf(env.srcpath, PATH_MAXLEN, "%s", dir);
	snprintf(env.objpath, PATH_MAXLEN, "%s/.obj", wd);
	snprintf(env.libpath, PATH_MAXLEN, "%s/.lib", wd);

	// pkg_makeroot(&env);
}

int do_test(int argc, char **argv) {
	
}


int main(int argc, char **argv) {
	env_init();
	compiler_init();
	cmd_init();

	if (argc == 1) {
		fprintf(stdout, "%s\n", usage);
		return 0;
	}

	if (strcmp(argv[1], "check") == 0) {
		testmain(argc, argv);
	} else if (strcmp(argv[1], "build") == 0) {
		do_build(argc - 2, argv + 2);
	} else if (strcmp(argv[1], "test") == 0) {
		do_test(argc - 2, argv + 2);
	}
}
