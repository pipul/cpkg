#ifndef _H_COMPILER_
#define _H_COMPILER_

#include "env.h"
#include "package.h"

struct compiler_ops {
	char *name;
	char **suffix;
	int suffix_len;
	void (*compile)(struct package *pkg);
	struct list_head alllink;
};



int compiler_register(struct compiler_ops *cpl);
int compiler_unregister(struct compiler_ops *cpl);

struct compiler_ops *get_compiler_by_name(const char *name);
struct compiler_ops *get_compiler_by_suffix(const char *suffix);


extern struct compiler_ops gcc_compiler;

void compiler_init();

#endif
