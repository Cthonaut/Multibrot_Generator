# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/john/Documents/Github_projects/Multibrot_Generator/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/john/Documents/Github_projects/Multibrot_Generator/build/debug

# Include any dependencies generated for this target.
include CMakeFiles/Multibrot_Generator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Multibrot_Generator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Multibrot_Generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Multibrot_Generator.dir/flags.make

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o: CMakeFiles/Multibrot_Generator.dir/flags.make
CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o: /home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp
CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o: CMakeFiles/Multibrot_Generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/john/Documents/Github_projects/Multibrot_Generator/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o -MF CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o.d -o CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o -c /home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp > CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.i

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp -o CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.s

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o: CMakeFiles/Multibrot_Generator.dir/flags.make
CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o: /home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c
CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o: CMakeFiles/Multibrot_Generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/john/Documents/Github_projects/Multibrot_Generator/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o -MF CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o.d -o CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o -c /home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c > CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.i

CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c -o CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.s

# Object files for target Multibrot_Generator
Multibrot_Generator_OBJECTS = \
"CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o" \
"CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o"

# External object files for target Multibrot_Generator
Multibrot_Generator_EXTERNAL_OBJECTS =

Multibrot_Generator: CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/Main.cpp.o
Multibrot_Generator: CMakeFiles/Multibrot_Generator.dir/home/john/Documents/Github_projects/Multibrot_Generator/src/glad.c.o
Multibrot_Generator: CMakeFiles/Multibrot_Generator.dir/build.make
Multibrot_Generator: /usr/lib64/libX11.so
Multibrot_Generator: CMakeFiles/Multibrot_Generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/john/Documents/Github_projects/Multibrot_Generator/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Multibrot_Generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Multibrot_Generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Multibrot_Generator.dir/build: Multibrot_Generator
.PHONY : CMakeFiles/Multibrot_Generator.dir/build

CMakeFiles/Multibrot_Generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Multibrot_Generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Multibrot_Generator.dir/clean

CMakeFiles/Multibrot_Generator.dir/depend:
	cd /home/john/Documents/Github_projects/Multibrot_Generator/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/john/Documents/Github_projects/Multibrot_Generator/build /home/john/Documents/Github_projects/Multibrot_Generator/build /home/john/Documents/Github_projects/Multibrot_Generator/build/debug /home/john/Documents/Github_projects/Multibrot_Generator/build/debug /home/john/Documents/Github_projects/Multibrot_Generator/build/debug/CMakeFiles/Multibrot_Generator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Multibrot_Generator.dir/depend

