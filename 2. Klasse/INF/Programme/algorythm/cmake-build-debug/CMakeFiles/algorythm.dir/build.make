# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\2. Klasse\INF\Programme\algorythm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/algorythm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorythm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorythm.dir/flags.make

CMakeFiles/algorythm.dir/main.cpp.obj: CMakeFiles/algorythm.dir/flags.make
CMakeFiles/algorythm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorythm.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\algorythm.dir\main.cpp.obj -c "H:\2. Klasse\INF\Programme\algorythm\main.cpp"

CMakeFiles/algorythm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorythm.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\2. Klasse\INF\Programme\algorythm\main.cpp" > CMakeFiles\algorythm.dir\main.cpp.i

CMakeFiles/algorythm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorythm.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\2. Klasse\INF\Programme\algorythm\main.cpp" -o CMakeFiles\algorythm.dir\main.cpp.s

CMakeFiles/algorythm.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/algorythm.dir/main.cpp.obj.requires

CMakeFiles/algorythm.dir/main.cpp.obj.provides: CMakeFiles/algorythm.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\algorythm.dir\build.make CMakeFiles/algorythm.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/algorythm.dir/main.cpp.obj.provides

CMakeFiles/algorythm.dir/main.cpp.obj.provides.build: CMakeFiles/algorythm.dir/main.cpp.obj


# Object files for target algorythm
algorythm_OBJECTS = \
"CMakeFiles/algorythm.dir/main.cpp.obj"

# External object files for target algorythm
algorythm_EXTERNAL_OBJECTS =

algorythm.exe: CMakeFiles/algorythm.dir/main.cpp.obj
algorythm.exe: CMakeFiles/algorythm.dir/build.make
algorythm.exe: CMakeFiles/algorythm.dir/linklibs.rsp
algorythm.exe: CMakeFiles/algorythm.dir/objects1.rsp
algorythm.exe: CMakeFiles/algorythm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorythm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorythm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorythm.dir/build: algorythm.exe

.PHONY : CMakeFiles/algorythm.dir/build

CMakeFiles/algorythm.dir/requires: CMakeFiles/algorythm.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/algorythm.dir/requires

CMakeFiles/algorythm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorythm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorythm.dir/clean

CMakeFiles/algorythm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\2. Klasse\INF\Programme\algorythm" "H:\2. Klasse\INF\Programme\algorythm" "H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug" "H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug" "H:\2. Klasse\INF\Programme\algorythm\cmake-build-debug\CMakeFiles\algorythm.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/algorythm.dir/depend

