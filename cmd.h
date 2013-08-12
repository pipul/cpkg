#ifndef _H_CMD_
#define _H_CMD_

#include "list.h"
#include "slice.h"
#include "package.h"

struct cmd_ops {
	char *name;
	void (*cmd_process)(struct package *package, int argc, char **argv);
	struct list_head alllink;
};



int cmd_register(struct cmd_ops *cmd);
int cmd_unregister(struct cmd_ops *cmd);

#define DEFCMD_MAXARGC 16

struct cmd_ops *get_cmd_by_name(const char *name);


extern struct cmd_ops cmd_version;
extern struct cmd_ops cmd_build;
extern struct cmd_ops cmd_addlibrary;

void cmd_init();



#endif
