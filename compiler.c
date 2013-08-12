#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "package.h"
#include "compiler.h"

static struct list_head compiler_list;

int compiler_register(struct compiler_ops *cpl) {
	list_add(&cpl->alllink, &compiler_list);
}


int compiler_unregister(struct compiler_ops *cpl) {
	list_del(&cpl->alllink);
}


struct compiler_ops *get_compiler_by_name(const char *name) {
	struct compiler_ops *cpl;
	
	list_for_each_entry(cpl, &compiler_list, struct compiler_ops, alllink) {
		if (strcmp(cpl->name, name) == 0)
			return cpl;
	}
	return NULL;
}


struct compiler_ops *get_compiler_by_suffix(const char *suffix) {
	struct compiler_ops *cpl;
	int i;
	
	list_for_each_entry(cpl, &compiler_list, struct compiler_ops, alllink) {
		for (i = 0; i < cpl->suffix_len; i++) {
			if (strcmp(cpl->suffix[i], suffix) == 0)
				return cpl;
		}
	}
	return NULL;
}


void compiler_init(void) {
	INIT_LIST_HEAD(&compiler_list);
	compiler_register(&gcc_compiler);
}
