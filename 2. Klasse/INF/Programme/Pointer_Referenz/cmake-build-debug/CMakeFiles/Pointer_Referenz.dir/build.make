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
CMAKE_SOURCE_DIR = "H:\2. Klasse\Inf\Pointer_Referenz"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Pointer_Referenz.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pointer_Referenz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pointer_Referenz.dir/flags.make

CMakeFiles/Pointer_Referenz.dir/main.cpp.obj: CMakeFiles/Pointer_Referenz.dir/flags.make
CMakeFiles/Pointer_Referenz.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pointer_Referenz.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Pointer_Referenz.dir\main.cpp.obj -c "H:\2. Klasse\Inf\Pointer_Referenz\main.cpp"

CMakeFiles/Pointer_Referenz.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pointer_Referenz.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\2. Klasse\Inf\Pointer_Referenz\main.cpp" > CMakeFiles\Pointer_Referenz.dir\main.cpp.i

CMakeFiles/Pointer_Referenz.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pointer_Referenz.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\2. Klasse\Inf\Pointer_Referenz\main.cpp" -o CMakeFiles\Pointer_Referenz.dir\main.cpp.s

CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.requires

CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.provides: CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Pointer_Referenz.dir\build.make CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.provides

CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.provides.build: CMakeFiles/Pointer_Referenz.dir/main.cpp.obj


# Object files for target Pointer_Referenz
Pointer_Referenz_OBJECTS = \
"CMakeFiles/Pointer_Referenz.dir/main.cpp.obj"

# External object files for target Pointer_Referenz
Pointer_Referenz_EXTERNAL_OBJECTS =

Pointer_Referenz.exe: CMakeFiles/Pointer_Referenz.dir/main.cpp.obj
Pointer_Referenz.exe: CMakeFiles/Pointer_Referenz.dir/build.make
Pointer_Referenz.exe: CMakeFiles/Pointer_Referenz.dir/linklibs.rsp
Pointer_Referenz.exe: CMakeFiles/Pointer_Referenz.dir/objects1.rsp
Pointer_Referenz.exe: CMakeFiles/Pointer_Referenz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pointer_Referenz.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pointer_Referenz.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pointer_Referenz.dir/build: Pointer_Referenz.exe

.PHONY : CMakeFiles/Pointer_Referenz.dir/build

CMakeFiles/Pointer_Referenz.dir/requires: CMakeFiles/Pointer_Referenz.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Pointer_Referenz.dir/requires

CMakeFiles/Pointer_Referenz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pointer_Referenz.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pointer_Referenz.dir/clean

CMakeFiles/Pointer_Referenz.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\2. Klasse\Inf\Pointer_Referenz" "H:\2. Klasse\Inf\Pointer_Referenz" "H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug" "H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug" "H:\2. Klasse\Inf\Pointer_Referenz\cmake-build-debug\CMakeFiles\Pointer_Referenz.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Pointer_Referenz.dir/depend

