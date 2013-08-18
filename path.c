#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#include "env.h"
#include "path.h"
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


int path_mkdir(const char *filename, mode_t mode, int flags) {
	char *name = (char *)filename;
	char *tail = name + strlen(name);
	char fullpath[PATH_MAXLEN] = {};
	int len = 0, limit;
	struct stat finfo;
	
	if (flags & MKDIR_PARENT)
		goto mkdir_parent;
	return mkdir(filename, mode);
 mkdir_parent:

	/* At this point we know we have a real path component */
	if (name[0] == '/') {
		chdir("/");
	}
	for (;;) {
		if (name > tail) {
			break;
		}
		len = 0;
		limit = strlen(name);
		while (name[len] != '/' && len < limit) {
			len++;
		}
		if (!len) {
			name++;
			continue;
		}
		strncpy(fullpath, name, len);
		fullpath[len] = '\0';
		
		if (0 == stat(fullpath, &finfo)) {
			if (S_ISDIR(finfo.st_mode))
				goto path_ok;
			fprintf(stderr, "mkdir failed: %s is a file\n", fullpath);
			return -1;
		}

		if (0 != mkdir(fullpath, mode)) {
			fprintf(stderr, "mkdir error %s of %s\n", filename, fullpath);
			return -1;
		}
	path_ok:
		chdir(fullpath);
		name += len + 1;
	}
	return 0;
}
