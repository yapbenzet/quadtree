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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alperen/github/quadtree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alperen/github/quadtree/build

# Include any dependencies generated for this target.
include CMakeFiles/quadtree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quadtree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quadtree.dir/flags.make

CMakeFiles/quadtree.dir/main.cpp.o: CMakeFiles/quadtree.dir/flags.make
CMakeFiles/quadtree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alperen/github/quadtree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quadtree.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quadtree.dir/main.cpp.o -c /home/alperen/github/quadtree/main.cpp

CMakeFiles/quadtree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quadtree.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alperen/github/quadtree/main.cpp > CMakeFiles/quadtree.dir/main.cpp.i

CMakeFiles/quadtree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quadtree.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alperen/github/quadtree/main.cpp -o CMakeFiles/quadtree.dir/main.cpp.s

CMakeFiles/quadtree.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/quadtree.dir/main.cpp.o.requires

CMakeFiles/quadtree.dir/main.cpp.o.provides: CMakeFiles/quadtree.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/quadtree.dir/build.make CMakeFiles/quadtree.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/quadtree.dir/main.cpp.o.provides

CMakeFiles/quadtree.dir/main.cpp.o.provides.build: CMakeFiles/quadtree.dir/main.cpp.o


# Object files for target quadtree
quadtree_OBJECTS = \
"CMakeFiles/quadtree.dir/main.cpp.o"

# External object files for target quadtree
quadtree_EXTERNAL_OBJECTS =

quadtree: CMakeFiles/quadtree.dir/main.cpp.o
quadtree: CMakeFiles/quadtree.dir/build.make
quadtree: CMakeFiles/quadtree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alperen/github/quadtree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quadtree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quadtree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quadtree.dir/build: quadtree

.PHONY : CMakeFiles/quadtree.dir/build

CMakeFiles/quadtree.dir/requires: CMakeFiles/quadtree.dir/main.cpp.o.requires

.PHONY : CMakeFiles/quadtree.dir/requires

CMakeFiles/quadtree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quadtree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quadtree.dir/clean

CMakeFiles/quadtree.dir/depend:
	cd /home/alperen/github/quadtree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alperen/github/quadtree /home/alperen/github/quadtree /home/alperen/github/quadtree/build /home/alperen/github/quadtree/build /home/alperen/github/quadtree/build/CMakeFiles/quadtree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quadtree.dir/depend

