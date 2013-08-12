#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "env.h"
#include "compiler.h"


int main(int argc, char **argv) {
	compiler_init();
	testmain(argc, argv);
}
