# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/untitled/diploma

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/untitled/diploma/build

# Include any dependencies generated for this target.
include CMakeFiles/RingLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RingLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RingLib.dir/flags.make

CMakeFiles/RingLib.dir/src/ringsignature.cpp.o: CMakeFiles/RingLib.dir/flags.make
CMakeFiles/RingLib.dir/src/ringsignature.cpp.o: ../src/ringsignature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/untitled/diploma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RingLib.dir/src/ringsignature.cpp.o"
	/usr/local/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RingLib.dir/src/ringsignature.cpp.o -c /home/user/untitled/diploma/src/ringsignature.cpp

CMakeFiles/RingLib.dir/src/ringsignature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RingLib.dir/src/ringsignature.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/untitled/diploma/src/ringsignature.cpp > CMakeFiles/RingLib.dir/src/ringsignature.cpp.i

CMakeFiles/RingLib.dir/src/ringsignature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RingLib.dir/src/ringsignature.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/untitled/diploma/src/ringsignature.cpp -o CMakeFiles/RingLib.dir/src/ringsignature.cpp.s

CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.requires:

.PHONY : CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.requires

CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.provides: CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.requires
	$(MAKE) -f CMakeFiles/RingLib.dir/build.make CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.provides.build
.PHONY : CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.provides

CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.provides.build: CMakeFiles/RingLib.dir/src/ringsignature.cpp.o


# Object files for target RingLib
RingLib_OBJECTS = \
"CMakeFiles/RingLib.dir/src/ringsignature.cpp.o"

# External object files for target RingLib
RingLib_EXTERNAL_OBJECTS =

libRingLib.a: CMakeFiles/RingLib.dir/src/ringsignature.cpp.o
libRingLib.a: CMakeFiles/RingLib.dir/build.make
libRingLib.a: CMakeFiles/RingLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/untitled/diploma/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRingLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/RingLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RingLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RingLib.dir/build: libRingLib.a

.PHONY : CMakeFiles/RingLib.dir/build

CMakeFiles/RingLib.dir/requires: CMakeFiles/RingLib.dir/src/ringsignature.cpp.o.requires

.PHONY : CMakeFiles/RingLib.dir/requires

CMakeFiles/RingLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RingLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RingLib.dir/clean

CMakeFiles/RingLib.dir/depend:
	cd /home/user/untitled/diploma/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/untitled/diploma /home/user/untitled/diploma /home/user/untitled/diploma/build /home/user/untitled/diploma/build /home/user/untitled/diploma/build/CMakeFiles/RingLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RingLib.dir/depend

