#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#include "env.h"
#include "slice.h"



char *path_base(const char *filename) {
	char *pos;

	while ((pos = strstr(filename, "/")) != NULL) {
		filename = pos + 1;
	}
	return strdup(filename);
}


char *path_dir(const char *filename) {
	char *pos;
	const char *dir = filename;

	while ((pos = strstr(filename, "/")) != NULL) {
		filename = pos + 1;
	}
	return strndup(dir, filename - dir);
}


int path_isfile(const char *filename) {
	struct stat finfo;
	if ((stat(filename, &finfo)) != 0)
		return 0;
	return S_ISREG(finfo.st_mode);
}


int path_isdir(const char *filename) {
	struct stat finfo;
	if ((stat(filename, &finfo)) != 0)
		return 0;
	return S_ISDIR(finfo.st_mode);
}


char *path_ext(const char *filename) {
	char *pos;

	while ((pos = strstr(filename, ".")) != NULL) {
		filename = pos + 1;
	}
	return strdup(filename);
}


int path_walk(const char *pathname, struct slice *ents) {
	DIR *dir;
	struct dirent *ent;
	char fullpath[PATH_MAXLEN];

	if (!(dir = opendir(pathname))) {
		return -1;
	}
	while ((ent = readdir(dir)) != NULL) {
		if (strcmp(ent->d_name, ".") == 0
		    || strcmp(ent->d_name, "..") == 0)
			continue;
		sprintf(fullpath, "%s/%s", pathname, ent->d_name);
		slice_append(ents, strdup(fullpath));
	}

	closedir(dir);
	return 0;
}
