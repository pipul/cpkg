#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>


#include "path.h"
#include "slice.h"
#include "list.h"
#include "package.h"
#include "compiler.h"

// helper function for debug
void pkg_printf(struct package *pkg) {
	int i;
	struct package *subpkg;
	
	fprintf(stdout, "%s\n", pkg->name);
	for (i = 0; i < slice_size(&pkg->aux_source); i++) {
		fprintf(stdout, "\t%s\n", slice_get(&pkg->aux_source, i));
	}
	list_for_each_entry(subpkg, &pkg->subpkgs, struct package, child) {
		pkg_printf(subpkg);
	}
	return;
}

int test_package() {
	struct package *pkg;
	struct env env = {
		.srcpath = "/home/fangdong/cpkgroot/src",
		.libpath = "/home/fangdong/cpkgroot/lib",
		.objpath = "/home/fangdong/cpkgroot/obj",
		.includepath = "/home/fangdong/cpkgroot/include",
	};
	INIT_LIST_HEAD(&env.allpackages);
	pkg_makeroot(&env);
	list_add(&env.alllink, &env_list);
	list_for_each_entry(pkg, &env.allpackages, struct package, child) {
		pkg_printf(pkg);
		pkg_load_definitions(pkg);
		pkg_process_command(pkg);
	}

	if (!(pkg = pkg_find("base")))
		fprintf(stderr, "can't find base package\n");
	if (!(pkg = pkg_find("base/ae")))
		fprintf(stderr, "can't find base/ae package\n");
	if (!(pkg = pkg_find("base/ae/foo")))
		fprintf(stderr, "can't find base/ae/foo package\n");
	if (pkg = pkg_find("foo"))
		fprintf(stderr, "find an not exist package: foo\n");
	if (!(pkg = pkg_find("base/net")))
		fprintf(stderr, "can't find net package\n");
	if (pkg = pkg_find("net/oom"))
		fprintf(stderr, "find an not exist package: net/oom\n");

	// todo...
	// clean the pkg resource
	return 0;
}

int test_str() {
	int len, i;
	char *res[1000];
	char buf[BUFFER_MAXLEN] = "zifuchuan;weibn;waha, ok";
	char buf2[BUFFER_MAXLEN] = "zifuchua---eib---aha, ok";

	if (!strprefix("hahaweibo", "hah"))
		fprintf(stderr, "strprefix test error\n");
	if (!strsuffix("hahaweibo", "weibo"))
		fprintf(stderr, "strsuffix test error\n");
	len = strsplit("haha; weibo; haha; sdfd;dddxxx;weibo;", ";", res, 1000);
	if (len != 6)
		fprintf(stderr, "strsplit test error\n");
	for (i = 0; i < len; i++)
		free(res[i]);

	if (!strreplace(buf, "n;w", "---", 0) || strcmp(buf, buf2) != 0)
		fprintf(stderr, "strreplace failed: %s %s\n", buf, buf2);

	fprintf(stdout, "test_str done\n");
	return 0;
}

int test_compiler() {
	struct compiler_ops *cpl;

	cpl = get_compiler_by_name("gcc");
	if (!cpl || strcmp("gcc", cpl->name) != 0)
		fprintf(stderr, "get_compiler_by_name failed\n");
	cpl = get_compiler_by_name("lcc");
	if (cpl)
		fprintf(stderr,
			"get_compiler_by_name failed: found a not exist compiler\n");
}


int test_path() {
	struct stat finfo;
	char *filename = "/tmp/src/base/cpkg.c";
	char *pos;

	pos = path_base(filename);
	if (strcmp(pos, "cpkg.c") != 0) {
		fprintf(stderr, "invalid base name: %s\n", pos);
	}
	free(pos);

	pos = path_dir(filename);
	if (strcmp(pos, "/tmp/src/base") != 0) {
		fprintf(stderr, "invalid dir: %s\n", pos);
	}
	free(pos);

	if (!path_isfile(filename)) {
		fprintf(stderr, "the path is a file...\n");
	}

	if (path_isdir(filename)) {
		fprintf(stderr, "the path isn't a dir...\n");
	}

	pos = path_ext(filename);
	if (strcmp(pos, "c") != 0) {
		fprintf(stderr, "invalid ext: %s\n", pos);
	}
	free(pos);

	filename = "/tmp/haha/weibo/mm/goo";
	if (0 != path_mkdir(filename, 0755, 1)) {
		fprintf(stderr, "mkdir failed %s\n", filename);
		abort();
	}
	if (0 != stat(filename, &finfo)) {
		fprintf(stderr, "stat dir failed %s\n", filename);
		abort();
	}
	rmdir(filename);

	filename = "/tmp/haha//weibo/mm///goo";
	if (0 != path_mkdir(filename, 0755, 1)) {
		fprintf(stderr, "mkdir failed %s\n", filename);
		abort();
	}
	if (0 != stat(filename, &finfo)) {
		fprintf(stderr, "stat dir failed %s\n", filename);
		abort();
	}
	rmdir(filename);

	return 0;
}

int testmain(int argc, char **argv) {
	env_init();
	cmd_init();
	
	test_path();
	test_package();
	test_str();
	test_compiler();
}
