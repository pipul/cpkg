#ifndef _H_ENV_
#define _H_ENV_

#include "list.h"
#include <limits.h>

#define PATH_MAXLEN PATH_MAX
#define BUFFER_MAXLEN 1024
#define PACKAGE_PATH_LEN 256


struct env {
	char srcpath[PATH_MAXLEN];
	char libpath[PATH_MAXLEN];
	char objpath[PATH_MAXLEN];
	char includepath[PATH_MAXLEN];
	struct list_head alllink;
	struct list_head allpackages;
};


extern struct list_head env_list;

// init the global env.
int env_init();

int env_make(struct env *ev, const char *path);


#endif
