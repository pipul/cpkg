#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "env.h"
#include "compiler.h"


int main(int argc, char **argv) {
	env_init();
	compiler_init();
	cmd_init();
	
	testmain(argc, argv);
}
