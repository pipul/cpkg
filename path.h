#ifndef _H_PATH_
#define _H_PATH_

#include <sys/types.h>


char *path_base(const char *filename);
char *path_dir(const char *filename);
int path_isfile(const char *filename);
int path_isdir(const char *filename);
char *path_ext(const char *filename);

#define MKDIR_PARENT 0x01
int path_mkdir(const char *filename, mode_t mode, int flags);




















#endif
