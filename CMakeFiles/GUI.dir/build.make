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
CMAKE_SOURCE_DIR = /home/cm/codes/c++/geoInf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cm/codes/c++/geoInf

# Include any dependencies generated for this target.
include CMakeFiles/GUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GUI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GUI.dir/flags.make

CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o: src/clients/GUI/GUIclient.c
CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/geoInf/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o -MF CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o.d -o CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o -c /home/cm/codes/c++/geoInf/src/clients/GUI/GUIclient.c

CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cm/codes/c++/geoInf/src/clients/GUI/GUIclient.c > CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.i

CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cm/codes/c++/geoInf/src/clients/GUI/GUIclient.c -o CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.s

CMakeFiles/GUI.dir/src/include/utility.c.o: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/src/include/utility.c.o: src/include/utility.c
CMakeFiles/GUI.dir/src/include/utility.c.o: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/geoInf/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GUI.dir/src/include/utility.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/src/include/utility.c.o -MF CMakeFiles/GUI.dir/src/include/utility.c.o.d -o CMakeFiles/GUI.dir/src/include/utility.c.o -c /home/cm/codes/c++/geoInf/src/include/utility.c

CMakeFiles/GUI.dir/src/include/utility.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GUI.dir/src/include/utility.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cm/codes/c++/geoInf/src/include/utility.c > CMakeFiles/GUI.dir/src/include/utility.c.i

CMakeFiles/GUI.dir/src/include/utility.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GUI.dir/src/include/utility.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cm/codes/c++/geoInf/src/include/utility.c -o CMakeFiles/GUI.dir/src/include/utility.c.s

CMakeFiles/GUI.dir/src/include/cm_string.c.o: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/src/include/cm_string.c.o: src/include/cm_string.c
CMakeFiles/GUI.dir/src/include/cm_string.c.o: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/geoInf/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GUI.dir/src/include/cm_string.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/src/include/cm_string.c.o -MF CMakeFiles/GUI.dir/src/include/cm_string.c.o.d -o CMakeFiles/GUI.dir/src/include/cm_string.c.o -c /home/cm/codes/c++/geoInf/src/include/cm_string.c

CMakeFiles/GUI.dir/src/include/cm_string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GUI.dir/src/include/cm_string.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cm/codes/c++/geoInf/src/include/cm_string.c > CMakeFiles/GUI.dir/src/include/cm_string.c.i

CMakeFiles/GUI.dir/src/include/cm_string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GUI.dir/src/include/cm_string.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cm/codes/c++/geoInf/src/include/cm_string.c -o CMakeFiles/GUI.dir/src/include/cm_string.c.s

CMakeFiles/GUI.dir/src/database/dataController.c.o: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/src/database/dataController.c.o: src/database/dataController.c
CMakeFiles/GUI.dir/src/database/dataController.c.o: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/geoInf/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/GUI.dir/src/database/dataController.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/src/database/dataController.c.o -MF CMakeFiles/GUI.dir/src/database/dataController.c.o.d -o CMakeFiles/GUI.dir/src/database/dataController.c.o -c /home/cm/codes/c++/geoInf/src/database/dataController.c

CMakeFiles/GUI.dir/src/database/dataController.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GUI.dir/src/database/dataController.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cm/codes/c++/geoInf/src/database/dataController.c > CMakeFiles/GUI.dir/src/database/dataController.c.i

CMakeFiles/GUI.dir/src/database/dataController.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GUI.dir/src/database/dataController.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cm/codes/c++/geoInf/src/database/dataController.c -o CMakeFiles/GUI.dir/src/database/dataController.c.s

# Object files for target GUI
GUI_OBJECTS = \
"CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o" \
"CMakeFiles/GUI.dir/src/include/utility.c.o" \
"CMakeFiles/GUI.dir/src/include/cm_string.c.o" \
"CMakeFiles/GUI.dir/src/database/dataController.c.o"

# External object files for target GUI
GUI_EXTERNAL_OBJECTS =

GUI: CMakeFiles/GUI.dir/src/clients/GUI/GUIclient.c.o
GUI: CMakeFiles/GUI.dir/src/include/utility.c.o
GUI: CMakeFiles/GUI.dir/src/include/cm_string.c.o
GUI: CMakeFiles/GUI.dir/src/database/dataController.c.o
GUI: CMakeFiles/GUI.dir/build.make
GUI: CMakeFiles/GUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/cm/codes/c++/geoInf/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable GUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GUI.dir/build: GUI
.PHONY : CMakeFiles/GUI.dir/build

CMakeFiles/GUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GUI.dir/clean

CMakeFiles/GUI.dir/depend:
	cd /home/cm/codes/c++/geoInf && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cm/codes/c++/geoInf /home/cm/codes/c++/geoInf /home/cm/codes/c++/geoInf /home/cm/codes/c++/geoInf /home/cm/codes/c++/geoInf/CMakeFiles/GUI.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GUI.dir/depend

