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
CMAKE_COMMAND = /cygdrive/c/Users/hasee/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/hasee/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/wangqingAlgorithm/sort/counting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/counting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/counting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/counting.dir/flags.make

CMakeFiles/counting.dir/main.cpp.o: CMakeFiles/counting.dir/flags.make
CMakeFiles/counting.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/counting.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/counting.dir/main.cpp.o -c /cygdrive/e/wangqingAlgorithm/sort/counting/main.cpp

CMakeFiles/counting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/counting.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/wangqingAlgorithm/sort/counting/main.cpp > CMakeFiles/counting.dir/main.cpp.i

CMakeFiles/counting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/counting.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/wangqingAlgorithm/sort/counting/main.cpp -o CMakeFiles/counting.dir/main.cpp.s

CMakeFiles/counting.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/counting.dir/main.cpp.o.requires

CMakeFiles/counting.dir/main.cpp.o.provides: CMakeFiles/counting.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/counting.dir/build.make CMakeFiles/counting.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/counting.dir/main.cpp.o.provides

CMakeFiles/counting.dir/main.cpp.o.provides.build: CMakeFiles/counting.dir/main.cpp.o


# Object files for target counting
counting_OBJECTS = \
"CMakeFiles/counting.dir/main.cpp.o"

# External object files for target counting
counting_EXTERNAL_OBJECTS =

counting.exe: CMakeFiles/counting.dir/main.cpp.o
counting.exe: CMakeFiles/counting.dir/build.make
counting.exe: CMakeFiles/counting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable counting.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/counting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/counting.dir/build: counting.exe

.PHONY : CMakeFiles/counting.dir/build

CMakeFiles/counting.dir/requires: CMakeFiles/counting.dir/main.cpp.o.requires

.PHONY : CMakeFiles/counting.dir/requires

CMakeFiles/counting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/counting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/counting.dir/clean

CMakeFiles/counting.dir/depend:
	cd /cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/wangqingAlgorithm/sort/counting /cygdrive/e/wangqingAlgorithm/sort/counting /cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug /cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug /cygdrive/e/wangqingAlgorithm/sort/counting/cmake-build-debug/CMakeFiles/counting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/counting.dir/depend

