#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cmd.h"



static struct list_head cmd_list;



struct cmd_ops *get_cmd_by_name(const char *name) {
	struct cmd_ops *cmd;

	list_for_each_entry(cmd, &cmd_list, struct cmd_ops, alllink) {
		if (strcmp(cmd->name, name) == 0)
			return cmd;
	}
	return NULL;
}


int cmd_register(struct cmd_ops *cmd) {
	list_add(&cmd->alllink, &cmd_list);
}

int cmd_unregister(struct cmd_ops *cmd) {
	list_del(&cmd->alllink);
}


void cmd_init() {
	INIT_LIST_HEAD(&cmd_list);
	cmd_register(&cmd_version);
	cmd_register(&cmd_build);
	cmd_register(&cmd_addlibrary);
}
