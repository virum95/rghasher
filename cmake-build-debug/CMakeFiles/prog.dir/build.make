# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/virum/Programming/CLion-2017.3.3/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/virum/Programming/CLion-2017.3.3/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/virum/CLionProjects/rg32hash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/virum/CLionProjects/rg32hash/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/src/prog.c.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/src/prog.c.o: ../src/prog.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/virum/CLionProjects/rg32hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prog.dir/src/prog.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prog.dir/src/prog.c.o   -c /home/virum/CLionProjects/rg32hash/src/prog.c

CMakeFiles/prog.dir/src/prog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prog.dir/src/prog.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/virum/CLionProjects/rg32hash/src/prog.c > CMakeFiles/prog.dir/src/prog.c.i

CMakeFiles/prog.dir/src/prog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prog.dir/src/prog.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/virum/CLionProjects/rg32hash/src/prog.c -o CMakeFiles/prog.dir/src/prog.c.s

CMakeFiles/prog.dir/src/prog.c.o.requires:

.PHONY : CMakeFiles/prog.dir/src/prog.c.o.requires

CMakeFiles/prog.dir/src/prog.c.o.provides: CMakeFiles/prog.dir/src/prog.c.o.requires
	$(MAKE) -f CMakeFiles/prog.dir/build.make CMakeFiles/prog.dir/src/prog.c.o.provides.build
.PHONY : CMakeFiles/prog.dir/src/prog.c.o.provides

CMakeFiles/prog.dir/src/prog.c.o.provides.build: CMakeFiles/prog.dir/src/prog.c.o


# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/src/prog.c.o"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

../bin/prog: CMakeFiles/prog.dir/src/prog.c.o
../bin/prog: CMakeFiles/prog.dir/build.make
../bin/prog: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/virum/CLionProjects/rg32hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: ../bin/prog

.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/requires: CMakeFiles/prog.dir/src/prog.c.o.requires

.PHONY : CMakeFiles/prog.dir/requires

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	cd /home/virum/CLionProjects/rg32hash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/virum/CLionProjects/rg32hash /home/virum/CLionProjects/rg32hash /home/virum/CLionProjects/rg32hash/cmake-build-debug /home/virum/CLionProjects/rg32hash/cmake-build-debug /home/virum/CLionProjects/rg32hash/cmake-build-debug/CMakeFiles/prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog.dir/depend

