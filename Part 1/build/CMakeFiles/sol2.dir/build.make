# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/chirag/Job Applications/AiFi/Part 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/chirag/Job Applications/AiFi/Part 1/build"

# Include any dependencies generated for this target.
include CMakeFiles/sol2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sol2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sol2.dir/flags.make

CMakeFiles/sol2.dir/src/sol2.c.o: CMakeFiles/sol2.dir/flags.make
CMakeFiles/sol2.dir/src/sol2.c.o: ../src/sol2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chirag/Job Applications/AiFi/Part 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sol2.dir/src/sol2.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sol2.dir/src/sol2.c.o   -c "/home/chirag/Job Applications/AiFi/Part 1/src/sol2.c"

CMakeFiles/sol2.dir/src/sol2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sol2.dir/src/sol2.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chirag/Job Applications/AiFi/Part 1/src/sol2.c" > CMakeFiles/sol2.dir/src/sol2.c.i

CMakeFiles/sol2.dir/src/sol2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sol2.dir/src/sol2.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chirag/Job Applications/AiFi/Part 1/src/sol2.c" -o CMakeFiles/sol2.dir/src/sol2.c.s

CMakeFiles/sol2.dir/src/sol2.c.o.requires:

.PHONY : CMakeFiles/sol2.dir/src/sol2.c.o.requires

CMakeFiles/sol2.dir/src/sol2.c.o.provides: CMakeFiles/sol2.dir/src/sol2.c.o.requires
	$(MAKE) -f CMakeFiles/sol2.dir/build.make CMakeFiles/sol2.dir/src/sol2.c.o.provides.build
.PHONY : CMakeFiles/sol2.dir/src/sol2.c.o.provides

CMakeFiles/sol2.dir/src/sol2.c.o.provides.build: CMakeFiles/sol2.dir/src/sol2.c.o


# Object files for target sol2
sol2_OBJECTS = \
"CMakeFiles/sol2.dir/src/sol2.c.o"

# External object files for target sol2
sol2_EXTERNAL_OBJECTS =

sol2: CMakeFiles/sol2.dir/src/sol2.c.o
sol2: CMakeFiles/sol2.dir/build.make
sol2: CMakeFiles/sol2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/chirag/Job Applications/AiFi/Part 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sol2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sol2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sol2.dir/build: sol2

.PHONY : CMakeFiles/sol2.dir/build

CMakeFiles/sol2.dir/requires: CMakeFiles/sol2.dir/src/sol2.c.o.requires

.PHONY : CMakeFiles/sol2.dir/requires

CMakeFiles/sol2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sol2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sol2.dir/clean

CMakeFiles/sol2.dir/depend:
	cd "/home/chirag/Job Applications/AiFi/Part 1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/chirag/Job Applications/AiFi/Part 1" "/home/chirag/Job Applications/AiFi/Part 1" "/home/chirag/Job Applications/AiFi/Part 1/build" "/home/chirag/Job Applications/AiFi/Part 1/build" "/home/chirag/Job Applications/AiFi/Part 1/build/CMakeFiles/sol2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sol2.dir/depend

