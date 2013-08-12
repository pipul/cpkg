#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "env.h"
#include "slice.h"

static char env_name[] = "CPKGROOT";
struct list_head env_list;

#define PACKAGE_ENV_LISTLEN 512

int env_init() {
	int len, i;
	struct env *env;
	char *res[PACKAGE_ENV_LISTLEN];
	char *env_value = getenv(env_name);

	INIT_LIST_HEAD(&env_list);
	if (!env_value)
		return 0;
	len = strsplit(env_value, ";", res, PACKAGE_ENV_LISTLEN);
	for (i = 0; i < len; i++) {
		env = malloc(sizeof(*env));
		if (!env)
			continue;
		env_make(env, res[i]);
		list_add(&env->alllink, &env_list);
		free(res[i]);
		pkg_makeroot(env);
	}
	return 0;
}

int env_make(struct env *ev, const char *path) {
	if (strlen(path) >= PACKAGE_PATH_LEN) {
		fprintf(stderr, "env init failed: %s\n", path);
		return -1;
	}
	sprintf(ev->objpath, "%s/obj/", path);
	sprintf(ev->srcpath, "%s/src/", path);
	sprintf(ev->libpath, "%s/pkg/", path);
	sprintf(ev->includepath, "%s/include/", path);
	return 0;
}


int env_check(struct env *ev, const char *path) {
	return strprefix(path, ev->srcpath);
}

