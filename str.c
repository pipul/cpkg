#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slice.h"



int strprefix(const char *haystack, const char *str) {
	if (!haystack || !str || strlen(haystack) < strlen(str))
		return 0;
	return strncmp(haystack, str, strlen(str)) == 0;
}


int strsuffix(const char *haystack, const char *str) {
	char *ptr;
	if (!haystack || !str || strlen(haystack) < strlen(str))
		return 0;
	if (!(ptr = strstr(haystack, str)))
		return 0;
	return strlen(ptr) == strlen(str);
}

int strsplit(const char *haystack, const char *str, char *res[], int size) {
	int i;
	char *pos;

	for (i = 0; i < size; i++) {
		pos = strstr(haystack, str);
		if (!pos) {
			if (strlen(haystack))
				res[i++] = strdup(haystack);
			break;
		}
		res[i] = strndup(haystack, pos - haystack);
		haystack = pos + strlen(str);
	}
	return i;
}

int strcontain(const char *haystack, const char *str) {
	char *ptr;

	if (!haystack || !str || strlen(haystack) < strlen(str))
		return 0;
	if (!(ptr = strstr(haystack, str)))
		return 0;
	return strlen(ptr) >= strlen(str);
}

int strreplace(char *haystack, char *str, char *rstr, int limit) {
	int i, len = strlen(str);
	char *ptr, *start = haystack;
	
	if (!haystack || !str || (rstr && strlen(rstr) != strlen(str)))
		return 0;
	start = haystack;
	if (!limit)
		limit = 9999; // to fix
	while ((ptr = strstr(start, str)) != NULL && limit) {
		for (i = 0; i < len; i++) {
			if (rstr)
				ptr[i] = rstr[i];
			else
				ptr[i] = '\0';
		}
		start = ptr + len;
		limit--;
	}
	return 1;
}



void slice_init(struct slice *s) {
	s->size = 0;
	s->cap = SLICE_DEFAULT_LEN;
	s->data = calloc(sizeof(void *), s->cap);
	return;
}

void slice_destroy(struct slice *s) {
	while (s->size) {
		// free(s->data[s->size - 1]);
		s->size--;
	}
	free(s->data);
	return;
}

void slice_append(struct slice *s, void *ptr) {
	if (s->size == s->cap) {
		s->cap = s->cap * 2;
		s->data = realloc(s->data, s->cap * sizeof(void *));
	}
	s->data[s->size++] = ptr;
	s->data[s->size] = NULL;
	return;
}

void slice_appendn(struct slice *s, int n, void **ptr) {
	int i;

	for (i = 0; i < n; i++) {
		slice_append(s, ptr[i]);
	}
	return;
}

void slice_merge_from(struct slice *s, struct slice *from) {
	slice_appendn(s, slice_size(from), slice_data(from));
}


int slice_size(struct slice *s) {
	return s->size;
}


void **slice_data(struct slice *s) {
	return s->data;
}

void *slice_get(struct slice *s, int idx) {
	if (idx >= s->size) {
		return NULL;
	}
	return s->data[idx];
}


void slice_remove(struct slice *s, int idx) {
	if (idx >= slice_size(s))
		return;
	s->data[idx] = s->data[s->size - 1];
	s->data[s->size - 1] = NULL;
	s->size--;
}

void slice_reset(struct slice *s) {
	s->size = 0;
}
