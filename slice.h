#ifndef _H_SLICE_
#define _H_SLICE_


#define SLICE_DEFAULT_LEN 10

struct slice {
	int cap;
	int size;
	void **data;
};

void slice_init(struct slice *s);
void slice_destroy(struct slice *s);
void slice_append(struct slice *s, void *ptr);
void slice_appendn(struct slice *s, int n, void **ptr);
void slice_merge_from(struct slice *s, struct slice *from);
int slice_size(struct slice *s);
void *slice_get(struct slice *s, int idx);
void **slice_data(struct slice *s);

#define list_for_each_elem(pos, slice)			   \
	for (pos = slice_data(slice);			   \
	     pos; \
	     pos++)



int strprefix(const char *haystack, const char *str);
int strsuffix(const char *haystack, const char *str);
int strsplit(const char *haystack, const char *str, char *res[], int size);
int strcontain(const char *haystack, const char *str);







#endif
