# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cm/codes/c++/geoInf/CMakeFiles /home/cm/codes/c++/geoInf//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cm/codes/c++/geoInf/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named GUI

# Build rule for target.
GUI: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 GUI
.PHONY : GUI

# fast build rule for target.
GUI/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/build
.PHONY : GUI/fast

#=============================================================================
# Target rules for targets named TUI

# Build rule for target.
TUI: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TUI
.PHONY : TUI

# fast build rule for target.
TUI/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/build
.PHONY : TUI/fast

src/GUIclient.o: src/GUIclient.c.o
.PHONY : src/GUIclient.o

# target to build an object file
src/GUIclient.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/GUIclient.c.o
.PHONY : src/GUIclient.c.o

src/GUIclient.i: src/GUIclient.c.i
.PHONY : src/GUIclient.i

# target to preprocess a source file
src/GUIclient.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/GUIclient.c.i
.PHONY : src/GUIclient.c.i

src/GUIclient.s: src/GUIclient.c.s
.PHONY : src/GUIclient.s

# target to generate assembly for a file
src/GUIclient.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/GUIclient.c.s
.PHONY : src/GUIclient.c.s

src/TUIclient.o: src/TUIclient.c.o
.PHONY : src/TUIclient.o

# target to build an object file
src/TUIclient.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/TUIclient.c.o
.PHONY : src/TUIclient.c.o

src/TUIclient.i: src/TUIclient.c.i
.PHONY : src/TUIclient.i

# target to preprocess a source file
src/TUIclient.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/TUIclient.c.i
.PHONY : src/TUIclient.c.i

src/TUIclient.s: src/TUIclient.c.s
.PHONY : src/TUIclient.s

# target to generate assembly for a file
src/TUIclient.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/TUIclient.c.s
.PHONY : src/TUIclient.c.s

src/database/dataController.o: src/database/dataController.c.o
.PHONY : src/database/dataController.o

# target to build an object file
src/database/dataController.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/database/dataController.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/database/dataController.c.o
.PHONY : src/database/dataController.c.o

src/database/dataController.i: src/database/dataController.c.i
.PHONY : src/database/dataController.i

# target to preprocess a source file
src/database/dataController.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/database/dataController.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/database/dataController.c.i
.PHONY : src/database/dataController.c.i

src/database/dataController.s: src/database/dataController.c.s
.PHONY : src/database/dataController.s

# target to generate assembly for a file
src/database/dataController.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/database/dataController.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/database/dataController.c.s
.PHONY : src/database/dataController.c.s

src/include/utility.o: src/include/utility.c.o
.PHONY : src/include/utility.o

# target to build an object file
src/include/utility.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/include/utility.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/include/utility.c.o
.PHONY : src/include/utility.c.o

src/include/utility.i: src/include/utility.c.i
.PHONY : src/include/utility.i

# target to preprocess a source file
src/include/utility.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/include/utility.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/include/utility.c.i
.PHONY : src/include/utility.c.i

src/include/utility.s: src/include/utility.c.s
.PHONY : src/include/utility.s

# target to generate assembly for a file
src/include/utility.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GUI.dir/build.make CMakeFiles/GUI.dir/src/include/utility.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/TUI.dir/build.make CMakeFiles/TUI.dir/src/include/utility.c.s
.PHONY : src/include/utility.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... GUI"
	@echo "... TUI"
	@echo "... src/GUIclient.o"
	@echo "... src/GUIclient.i"
	@echo "... src/GUIclient.s"
	@echo "... src/TUIclient.o"
	@echo "... src/TUIclient.i"
	@echo "... src/TUIclient.s"
	@echo "... src/database/dataController.o"
	@echo "... src/database/dataController.i"
	@echo "... src/database/dataController.s"
	@echo "... src/include/utility.o"
	@echo "... src/include/utility.i"
	@echo "... src/include/utility.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

