# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/m/mponomar/project/git/Corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Corewar.dir/flags.make

CMakeFiles/Corewar.dir/vm/controller/main.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/vm/controller/main.c.o: ../vm/controller/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Corewar.dir/vm/controller/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/vm/controller/main.c.o   -c /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/main.c

CMakeFiles/Corewar.dir/vm/controller/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/vm/controller/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/main.c > CMakeFiles/Corewar.dir/vm/controller/main.c.i

CMakeFiles/Corewar.dir/vm/controller/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/vm/controller/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/main.c -o CMakeFiles/Corewar.dir/vm/controller/main.c.s

CMakeFiles/Corewar.dir/vm/controller/main.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/vm/controller/main.c.o.requires

CMakeFiles/Corewar.dir/vm/controller/main.c.o.provides: CMakeFiles/Corewar.dir/vm/controller/main.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/vm/controller/main.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/vm/controller/main.c.o.provides

CMakeFiles/Corewar.dir/vm/controller/main.c.o.provides.build: CMakeFiles/Corewar.dir/vm/controller/main.c.o


CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o: ../vm/controller/get_flags.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o   -c /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/get_flags.c

CMakeFiles/Corewar.dir/vm/controller/get_flags.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/vm/controller/get_flags.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/get_flags.c > CMakeFiles/Corewar.dir/vm/controller/get_flags.c.i

CMakeFiles/Corewar.dir/vm/controller/get_flags.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/vm/controller/get_flags.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/m/mponomar/project/git/Corewar/vm/controller/get_flags.c -o CMakeFiles/Corewar.dir/vm/controller/get_flags.c.s

CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.requires

CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.provides: CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.provides

CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.provides.build: CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o


# Object files for target Corewar
Corewar_OBJECTS = \
"CMakeFiles/Corewar.dir/vm/controller/main.c.o" \
"CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o"

# External object files for target Corewar
Corewar_EXTERNAL_OBJECTS =

Corewar: CMakeFiles/Corewar.dir/vm/controller/main.c.o
Corewar: CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o
Corewar: CMakeFiles/Corewar.dir/build.make
Corewar: CMakeFiles/Corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Corewar.dir/build: Corewar

.PHONY : CMakeFiles/Corewar.dir/build

CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/vm/controller/main.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/vm/controller/get_flags.c.o.requires

.PHONY : CMakeFiles/Corewar.dir/requires

CMakeFiles/Corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Corewar.dir/clean

CMakeFiles/Corewar.dir/depend:
	cd /nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/m/mponomar/project/git/Corewar /nfs/2016/m/mponomar/project/git/Corewar /nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug /nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug /nfs/2016/m/mponomar/project/git/Corewar/cmake-build-debug/CMakeFiles/Corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Corewar.dir/depend

