# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gusy/apuntes/HPC/rghasher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gusy/apuntes/HPC/rghasher/build

# Include any dependencies generated for this target.
include CMakeFiles/hash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hash.dir/flags.make

CMakeFiles/hash.dir/src/hash.c.o: CMakeFiles/hash.dir/flags.make
CMakeFiles/hash.dir/src/hash.c.o: ../src/hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gusy/apuntes/HPC/rghasher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hash.dir/src/hash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hash.dir/src/hash.c.o   -c /home/gusy/apuntes/HPC/rghasher/src/hash.c

CMakeFiles/hash.dir/src/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hash.dir/src/hash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gusy/apuntes/HPC/rghasher/src/hash.c > CMakeFiles/hash.dir/src/hash.c.i

CMakeFiles/hash.dir/src/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hash.dir/src/hash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gusy/apuntes/HPC/rghasher/src/hash.c -o CMakeFiles/hash.dir/src/hash.c.s

# Object files for target hash
hash_OBJECTS = \
"CMakeFiles/hash.dir/src/hash.c.o"

# External object files for target hash
hash_EXTERNAL_OBJECTS =

../bin/hash: CMakeFiles/hash.dir/src/hash.c.o
../bin/hash: CMakeFiles/hash.dir/build.make
../bin/hash: CMakeFiles/hash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gusy/apuntes/HPC/rghasher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/hash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hash.dir/build: ../bin/hash

.PHONY : CMakeFiles/hash.dir/build

CMakeFiles/hash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hash.dir/clean

CMakeFiles/hash.dir/depend:
	cd /home/gusy/apuntes/HPC/rghasher/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gusy/apuntes/HPC/rghasher /home/gusy/apuntes/HPC/rghasher /home/gusy/apuntes/HPC/rghasher/build /home/gusy/apuntes/HPC/rghasher/build /home/gusy/apuntes/HPC/rghasher/build/CMakeFiles/hash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hash.dir/depend

