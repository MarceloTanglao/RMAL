# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /var/lib/snapd/snap/cmake/1005/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/cmake/1005/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build

# Include any dependencies generated for this target.
include CMakeFiles/Tutorial_Step4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tutorial_Step4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tutorial_Step4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tutorial_Step4.dir/flags.make

CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o: CMakeFiles/Tutorial_Step4.dir/flags.make
CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o: ../Tutorial_Step4.cxx
CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o: CMakeFiles/Tutorial_Step4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o -MF CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o.d -o CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o -c /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/Tutorial_Step4.cxx

CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/Tutorial_Step4.cxx > CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.i

CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/Tutorial_Step4.cxx -o CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.s

# Object files for target Tutorial_Step4
Tutorial_Step4_OBJECTS = \
"CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o"

# External object files for target Tutorial_Step4
Tutorial_Step4_EXTERNAL_OBJECTS =

Tutorial_Step4: CMakeFiles/Tutorial_Step4.dir/Tutorial_Step4.cxx.o
Tutorial_Step4: CMakeFiles/Tutorial_Step4.dir/build.make
Tutorial_Step4: /usr/lib/libvtkInteractionStyle.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingContextOpenGL2.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingGL2PSOpenGL2.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingOpenGL2.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingContext2D.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingFreeType.so.9.1.0
Tutorial_Step4: /usr/lib/libfreetype.so
Tutorial_Step4: /usr/lib/libvtkRenderingUI.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkRenderingCore.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonColor.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkFiltersSources.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkFiltersGeneral.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkFiltersCore.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonExecutionModel.so.9.1.0
Tutorial_Step4: /usr/lib/libGLEW.so
Tutorial_Step4: /usr/lib/libX11.so
Tutorial_Step4: /usr/lib/libvtkCommonDataModel.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonTransforms.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonMisc.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonMath.so.9.1.0
Tutorial_Step4: /usr/lib/libvtkCommonCore.so.9.1.0
Tutorial_Step4: /usr/lib/libvtksys.so.9.1.0
Tutorial_Step4: /usr/lib/libtbb.so.12.5
Tutorial_Step4: /usr/lib/libgomp.so
Tutorial_Step4: /usr/lib/libpthread.so
Tutorial_Step4: /usr/lib/libvtkkissfft.so.9.1.0
Tutorial_Step4: CMakeFiles/Tutorial_Step4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tutorial_Step4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial_Step4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tutorial_Step4.dir/build: Tutorial_Step4
.PHONY : CMakeFiles/Tutorial_Step4.dir/build

CMakeFiles/Tutorial_Step4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tutorial_Step4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tutorial_Step4.dir/clean

CMakeFiles/Tutorial_Step4.dir/depend:
	cd /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4 /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4 /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build /home/marcelot/Desktop/RMAL/VTKPractice/Tutorial_Step4/build/CMakeFiles/Tutorial_Step4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tutorial_Step4.dir/depend

