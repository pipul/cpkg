# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fangdong/work/cpkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fangdong/work/cpkg

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/cmd_version.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/cmd_version.c.o: cmd_version.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/cmd_version.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/cmd_version.c.o   -c /home/fangdong/work/cpkg/cmd_version.c

CMakeFiles/test.dir/cmd_version.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/cmd_version.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/cmd_version.c > CMakeFiles/test.dir/cmd_version.c.i

CMakeFiles/test.dir/cmd_version.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/cmd_version.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/cmd_version.c -o CMakeFiles/test.dir/cmd_version.c.s

CMakeFiles/test.dir/cmd_version.c.o.requires:
.PHONY : CMakeFiles/test.dir/cmd_version.c.o.requires

CMakeFiles/test.dir/cmd_version.c.o.provides: CMakeFiles/test.dir/cmd_version.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/cmd_version.c.o.provides.build
.PHONY : CMakeFiles/test.dir/cmd_version.c.o.provides

CMakeFiles/test.dir/cmd_version.c.o.provides.build: CMakeFiles/test.dir/cmd_version.c.o

CMakeFiles/test.dir/cpkg.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/cpkg.c.o: cpkg.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/cpkg.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/cpkg.c.o   -c /home/fangdong/work/cpkg/cpkg.c

CMakeFiles/test.dir/cpkg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/cpkg.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/cpkg.c > CMakeFiles/test.dir/cpkg.c.i

CMakeFiles/test.dir/cpkg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/cpkg.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/cpkg.c -o CMakeFiles/test.dir/cpkg.c.s

CMakeFiles/test.dir/cpkg.c.o.requires:
.PHONY : CMakeFiles/test.dir/cpkg.c.o.requires

CMakeFiles/test.dir/cpkg.c.o.provides: CMakeFiles/test.dir/cpkg.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/cpkg.c.o.provides.build
.PHONY : CMakeFiles/test.dir/cpkg.c.o.provides

CMakeFiles/test.dir/cpkg.c.o.provides.build: CMakeFiles/test.dir/cpkg.c.o

CMakeFiles/test.dir/compiler.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/compiler.c.o: compiler.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/compiler.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/compiler.c.o   -c /home/fangdong/work/cpkg/compiler.c

CMakeFiles/test.dir/compiler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/compiler.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/compiler.c > CMakeFiles/test.dir/compiler.c.i

CMakeFiles/test.dir/compiler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/compiler.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/compiler.c -o CMakeFiles/test.dir/compiler.c.s

CMakeFiles/test.dir/compiler.c.o.requires:
.PHONY : CMakeFiles/test.dir/compiler.c.o.requires

CMakeFiles/test.dir/compiler.c.o.provides: CMakeFiles/test.dir/compiler.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/compiler.c.o.provides.build
.PHONY : CMakeFiles/test.dir/compiler.c.o.provides

CMakeFiles/test.dir/compiler.c.o.provides.build: CMakeFiles/test.dir/compiler.c.o

CMakeFiles/test.dir/env.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/env.c.o: env.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/env.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/env.c.o   -c /home/fangdong/work/cpkg/env.c

CMakeFiles/test.dir/env.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/env.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/env.c > CMakeFiles/test.dir/env.c.i

CMakeFiles/test.dir/env.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/env.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/env.c -o CMakeFiles/test.dir/env.c.s

CMakeFiles/test.dir/env.c.o.requires:
.PHONY : CMakeFiles/test.dir/env.c.o.requires

CMakeFiles/test.dir/env.c.o.provides: CMakeFiles/test.dir/env.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/env.c.o.provides.build
.PHONY : CMakeFiles/test.dir/env.c.o.provides

CMakeFiles/test.dir/env.c.o.provides.build: CMakeFiles/test.dir/env.c.o

CMakeFiles/test.dir/str.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/str.c.o: str.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/str.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/str.c.o   -c /home/fangdong/work/cpkg/str.c

CMakeFiles/test.dir/str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/str.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/str.c > CMakeFiles/test.dir/str.c.i

CMakeFiles/test.dir/str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/str.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/str.c -o CMakeFiles/test.dir/str.c.s

CMakeFiles/test.dir/str.c.o.requires:
.PHONY : CMakeFiles/test.dir/str.c.o.requires

CMakeFiles/test.dir/str.c.o.provides: CMakeFiles/test.dir/str.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/str.c.o.provides.build
.PHONY : CMakeFiles/test.dir/str.c.o.provides

CMakeFiles/test.dir/str.c.o.provides.build: CMakeFiles/test.dir/str.c.o

CMakeFiles/test.dir/cmd_addlibrary.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/cmd_addlibrary.c.o: cmd_addlibrary.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/cmd_addlibrary.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/cmd_addlibrary.c.o   -c /home/fangdong/work/cpkg/cmd_addlibrary.c

CMakeFiles/test.dir/cmd_addlibrary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/cmd_addlibrary.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/cmd_addlibrary.c > CMakeFiles/test.dir/cmd_addlibrary.c.i

CMakeFiles/test.dir/cmd_addlibrary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/cmd_addlibrary.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/cmd_addlibrary.c -o CMakeFiles/test.dir/cmd_addlibrary.c.s

CMakeFiles/test.dir/cmd_addlibrary.c.o.requires:
.PHONY : CMakeFiles/test.dir/cmd_addlibrary.c.o.requires

CMakeFiles/test.dir/cmd_addlibrary.c.o.provides: CMakeFiles/test.dir/cmd_addlibrary.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/cmd_addlibrary.c.o.provides.build
.PHONY : CMakeFiles/test.dir/cmd_addlibrary.c.o.provides

CMakeFiles/test.dir/cmd_addlibrary.c.o.provides.build: CMakeFiles/test.dir/cmd_addlibrary.c.o

CMakeFiles/test.dir/cmd.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/cmd.c.o: cmd.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/cmd.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/cmd.c.o   -c /home/fangdong/work/cpkg/cmd.c

CMakeFiles/test.dir/cmd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/cmd.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/cmd.c > CMakeFiles/test.dir/cmd.c.i

CMakeFiles/test.dir/cmd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/cmd.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/cmd.c -o CMakeFiles/test.dir/cmd.c.s

CMakeFiles/test.dir/cmd.c.o.requires:
.PHONY : CMakeFiles/test.dir/cmd.c.o.requires

CMakeFiles/test.dir/cmd.c.o.provides: CMakeFiles/test.dir/cmd.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/cmd.c.o.provides.build
.PHONY : CMakeFiles/test.dir/cmd.c.o.provides

CMakeFiles/test.dir/cmd.c.o.provides.build: CMakeFiles/test.dir/cmd.c.o

CMakeFiles/test.dir/package.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/package.c.o: package.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/package.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/package.c.o   -c /home/fangdong/work/cpkg/package.c

CMakeFiles/test.dir/package.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/package.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/package.c > CMakeFiles/test.dir/package.c.i

CMakeFiles/test.dir/package.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/package.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/package.c -o CMakeFiles/test.dir/package.c.s

CMakeFiles/test.dir/package.c.o.requires:
.PHONY : CMakeFiles/test.dir/package.c.o.requires

CMakeFiles/test.dir/package.c.o.provides: CMakeFiles/test.dir/package.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/package.c.o.provides.build
.PHONY : CMakeFiles/test.dir/package.c.o.provides

CMakeFiles/test.dir/package.c.o.provides.build: CMakeFiles/test.dir/package.c.o

CMakeFiles/test.dir/compiler_gcc.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/compiler_gcc.c.o: compiler_gcc.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/compiler_gcc.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/compiler_gcc.c.o   -c /home/fangdong/work/cpkg/compiler_gcc.c

CMakeFiles/test.dir/compiler_gcc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/compiler_gcc.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/compiler_gcc.c > CMakeFiles/test.dir/compiler_gcc.c.i

CMakeFiles/test.dir/compiler_gcc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/compiler_gcc.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/compiler_gcc.c -o CMakeFiles/test.dir/compiler_gcc.c.s

CMakeFiles/test.dir/compiler_gcc.c.o.requires:
.PHONY : CMakeFiles/test.dir/compiler_gcc.c.o.requires

CMakeFiles/test.dir/compiler_gcc.c.o.provides: CMakeFiles/test.dir/compiler_gcc.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/compiler_gcc.c.o.provides.build
.PHONY : CMakeFiles/test.dir/compiler_gcc.c.o.provides

CMakeFiles/test.dir/compiler_gcc.c.o.provides.build: CMakeFiles/test.dir/compiler_gcc.c.o

CMakeFiles/test.dir/path.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/path.c.o: path.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/path.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/path.c.o   -c /home/fangdong/work/cpkg/path.c

CMakeFiles/test.dir/path.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/path.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/path.c > CMakeFiles/test.dir/path.c.i

CMakeFiles/test.dir/path.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/path.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/path.c -o CMakeFiles/test.dir/path.c.s

CMakeFiles/test.dir/path.c.o.requires:
.PHONY : CMakeFiles/test.dir/path.c.o.requires

CMakeFiles/test.dir/path.c.o.provides: CMakeFiles/test.dir/path.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/path.c.o.provides.build
.PHONY : CMakeFiles/test.dir/path.c.o.provides

CMakeFiles/test.dir/path.c.o.provides.build: CMakeFiles/test.dir/path.c.o

CMakeFiles/test.dir/cmd_build.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/cmd_build.c.o: cmd_build.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/cmd_build.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/cmd_build.c.o   -c /home/fangdong/work/cpkg/cmd_build.c

CMakeFiles/test.dir/cmd_build.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/cmd_build.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/cmd_build.c > CMakeFiles/test.dir/cmd_build.c.i

CMakeFiles/test.dir/cmd_build.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/cmd_build.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/cmd_build.c -o CMakeFiles/test.dir/cmd_build.c.s

CMakeFiles/test.dir/cmd_build.c.o.requires:
.PHONY : CMakeFiles/test.dir/cmd_build.c.o.requires

CMakeFiles/test.dir/cmd_build.c.o.provides: CMakeFiles/test.dir/cmd_build.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/cmd_build.c.o.provides.build
.PHONY : CMakeFiles/test.dir/cmd_build.c.o.provides

CMakeFiles/test.dir/cmd_build.c.o.provides.build: CMakeFiles/test.dir/cmd_build.c.o

CMakeFiles/test.dir/testunit.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/testunit.c.o: testunit.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fangdong/work/cpkg/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/test.dir/testunit.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/testunit.c.o   -c /home/fangdong/work/cpkg/testunit.c

CMakeFiles/test.dir/testunit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/testunit.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/fangdong/work/cpkg/testunit.c > CMakeFiles/test.dir/testunit.c.i

CMakeFiles/test.dir/testunit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/testunit.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/fangdong/work/cpkg/testunit.c -o CMakeFiles/test.dir/testunit.c.s

CMakeFiles/test.dir/testunit.c.o.requires:
.PHONY : CMakeFiles/test.dir/testunit.c.o.requires

CMakeFiles/test.dir/testunit.c.o.provides: CMakeFiles/test.dir/testunit.c.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/testunit.c.o.provides.build
.PHONY : CMakeFiles/test.dir/testunit.c.o.provides

CMakeFiles/test.dir/testunit.c.o.provides.build: CMakeFiles/test.dir/testunit.c.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/cmd_version.c.o" \
"CMakeFiles/test.dir/cpkg.c.o" \
"CMakeFiles/test.dir/compiler.c.o" \
"CMakeFiles/test.dir/env.c.o" \
"CMakeFiles/test.dir/str.c.o" \
"CMakeFiles/test.dir/cmd_addlibrary.c.o" \
"CMakeFiles/test.dir/cmd.c.o" \
"CMakeFiles/test.dir/package.c.o" \
"CMakeFiles/test.dir/compiler_gcc.c.o" \
"CMakeFiles/test.dir/path.c.o" \
"CMakeFiles/test.dir/cmd_build.c.o" \
"CMakeFiles/test.dir/testunit.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/cmd_version.c.o
test: CMakeFiles/test.dir/cpkg.c.o
test: CMakeFiles/test.dir/compiler.c.o
test: CMakeFiles/test.dir/env.c.o
test: CMakeFiles/test.dir/str.c.o
test: CMakeFiles/test.dir/cmd_addlibrary.c.o
test: CMakeFiles/test.dir/cmd.c.o
test: CMakeFiles/test.dir/package.c.o
test: CMakeFiles/test.dir/compiler_gcc.c.o
test: CMakeFiles/test.dir/path.c.o
test: CMakeFiles/test.dir/cmd_build.c.o
test: CMakeFiles/test.dir/testunit.c.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/cmd_version.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/cpkg.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/compiler.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/env.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/str.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/cmd_addlibrary.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/cmd.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/package.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/compiler_gcc.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/path.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/cmd_build.c.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/testunit.c.o.requires
.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/fangdong/work/cpkg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fangdong/work/cpkg /home/fangdong/work/cpkg /home/fangdong/work/cpkg /home/fangdong/work/cpkg /home/fangdong/work/cpkg/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
