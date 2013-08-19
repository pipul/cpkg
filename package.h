#ifndef _H_PACKAGE_
#define _H_PACKAGE_

#include "list.h"
#include "env.h"
#include "slice.h"
#include <string.h>
#include <stdlib.h>


#define PACKAGE_TOK_LEN 10

typedef enum {
	lang_c,
	lang_cpp,
	lang_java,
	lang_php,
	lang_go,
	lang_num
} pkg_type_t;

static char *pkg_tok[] = {
	".c",
	".cpp",
};


static inline char *pkg_type_to_tok(pkg_type_t type) {
	return pkg_tok[type];
}

static inline int check_pkg_source(char *path, pkg_type_t type) {
	return strsuffix(path, pkg_type_to_tok(type));
}


#define PKG_PENDING 0x01
#define PKG_DEPENDENCE_DONE 0x02

struct package {

	char name[PATH_MAXLEN];
	int status;
	struct env *env;

	struct slice aux_source;
	struct slice objs;
	struct slice cmdops;

	struct list_head child; // child of parent list
	struct list_head subpkgs; // our children packages
};

struct package *pkg_make(struct env *ev, char *path);
struct package *pkg_find(const char *pkg_name);
void pkg_build(struct package *pkg, pkg_type_t type);
void pkg_process_command(struct package *pkg);
void pkg_destroy(struct package *pkg);


// generate the Makefile
void pkg_autoconf(struct package *pkg);

#define DEFCONF_NAME "cpkgmk.txt"
void pkg_load_definitions(struct package *pkg);


#endif /* package */
