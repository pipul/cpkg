#ifndef _H_PATH_
#define _H_PATH_

#include <sys/types.h>
#include <dirent.h>
#include "slice.h"

char *path_base(const char *filename);
char *path_dir(const char *filename);
int path_isfile(const char *filename);
int path_isdir(const char *filename);
int path_walk(const char *filename, struct slice *ents);
int path_walktest(const char *filename, struct slice *ents,
		  int (*test)(struct dirent *dent));
int path_walkfile(const char *filename, struct slice *ents);
int path_walkdir(const char *filename, struct slice *ents);

char *path_ext(const char *filename);

#define MKDIR_PARENT 0x01
int path_mkdir(const char *filename, mode_t mode, int flags);




















#endif
