# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\julian\Documents\ucaProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\julian\Documents\ucaProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ucaProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ucaProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ucaProject.dir/flags.make

CMakeFiles/ucaProject.dir/main.cpp.obj: CMakeFiles/ucaProject.dir/flags.make
CMakeFiles/ucaProject.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\julian\Documents\ucaProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ucaProject.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ucaProject.dir\main.cpp.obj -c C:\Users\julian\Documents\ucaProject\main.cpp

CMakeFiles/ucaProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ucaProject.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\julian\Documents\ucaProject\main.cpp > CMakeFiles\ucaProject.dir\main.cpp.i

CMakeFiles/ucaProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ucaProject.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\julian\Documents\ucaProject\main.cpp -o CMakeFiles\ucaProject.dir\main.cpp.s

# Object files for target ucaProject
ucaProject_OBJECTS = \
"CMakeFiles/ucaProject.dir/main.cpp.obj"

# External object files for target ucaProject
ucaProject_EXTERNAL_OBJECTS =

ucaProject.exe: CMakeFiles/ucaProject.dir/main.cpp.obj
ucaProject.exe: CMakeFiles/ucaProject.dir/build.make
ucaProject.exe: CMakeFiles/ucaProject.dir/linklibs.rsp
ucaProject.exe: CMakeFiles/ucaProject.dir/objects1.rsp
ucaProject.exe: CMakeFiles/ucaProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\julian\Documents\ucaProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ucaProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ucaProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ucaProject.dir/build: ucaProject.exe

.PHONY : CMakeFiles/ucaProject.dir/build

CMakeFiles/ucaProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ucaProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ucaProject.dir/clean

CMakeFiles/ucaProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\julian\Documents\ucaProject C:\Users\julian\Documents\ucaProject C:\Users\julian\Documents\ucaProject\cmake-build-debug C:\Users\julian\Documents\ucaProject\cmake-build-debug C:\Users\julian\Documents\ucaProject\cmake-build-debug\CMakeFiles\ucaProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ucaProject.dir/depend

