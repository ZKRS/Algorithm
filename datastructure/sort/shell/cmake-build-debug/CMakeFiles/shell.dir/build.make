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
CMAKE_SOURCE_DIR = /cygdrive/e/wangqingAlgorithm/sort/shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shell.dir/flags.make

CMakeFiles/shell.dir/main.cpp.o: CMakeFiles/shell.dir/flags.make
CMakeFiles/shell.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shell.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shell.dir/main.cpp.o -c /cygdrive/e/wangqingAlgorithm/sort/shell/main.cpp

CMakeFiles/shell.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shell.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/wangqingAlgorithm/sort/shell/main.cpp > CMakeFiles/shell.dir/main.cpp.i

CMakeFiles/shell.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shell.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/wangqingAlgorithm/sort/shell/main.cpp -o CMakeFiles/shell.dir/main.cpp.s

CMakeFiles/shell.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/shell.dir/main.cpp.o.requires

CMakeFiles/shell.dir/main.cpp.o.provides: CMakeFiles/shell.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/shell.dir/build.make CMakeFiles/shell.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/shell.dir/main.cpp.o.provides

CMakeFiles/shell.dir/main.cpp.o.provides.build: CMakeFiles/shell.dir/main.cpp.o


# Object files for target shell
shell_OBJECTS = \
"CMakeFiles/shell.dir/main.cpp.o"

# External object files for target shell
shell_EXTERNAL_OBJECTS =

shell.exe: CMakeFiles/shell.dir/main.cpp.o
shell.exe: CMakeFiles/shell.dir/build.make
shell.exe: CMakeFiles/shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shell.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shell.dir/build: shell.exe

.PHONY : CMakeFiles/shell.dir/build

CMakeFiles/shell.dir/requires: CMakeFiles/shell.dir/main.cpp.o.requires

.PHONY : CMakeFiles/shell.dir/requires

CMakeFiles/shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shell.dir/clean

CMakeFiles/shell.dir/depend:
	cd /cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/wangqingAlgorithm/sort/shell /cygdrive/e/wangqingAlgorithm/sort/shell /cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug /cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug /cygdrive/e/wangqingAlgorithm/sort/shell/cmake-build-debug/CMakeFiles/shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shell.dir/depend

