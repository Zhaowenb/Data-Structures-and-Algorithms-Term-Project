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
CMAKE_COMMAND = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.c.o: /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/main.c
CMakeFiles/main.dir/src/main.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.c.o -MF CMakeFiles/main.dir/src/main.c.o.d -o CMakeFiles/main.dir/src/main.c.o -c /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/main.c

CMakeFiles/main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/main.c > CMakeFiles/main.dir/src/main.c.i

CMakeFiles/main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/main.c -o CMakeFiles/main.dir/src/main.c.s

CMakeFiles/main.dir/src/Line.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Line.c.o: /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/Line.c
CMakeFiles/main.dir/src/Line.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/src/Line.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/Line.c.o -MF CMakeFiles/main.dir/src/Line.c.o.d -o CMakeFiles/main.dir/src/Line.c.o -c /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/Line.c

CMakeFiles/main.dir/src/Line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/src/Line.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/Line.c > CMakeFiles/main.dir/src/Line.c.i

CMakeFiles/main.dir/src/Line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/src/Line.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/Line.c -o CMakeFiles/main.dir/src/Line.c.s

CMakeFiles/main.dir/src/booking.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/booking.c.o: /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booking.c
CMakeFiles/main.dir/src/booking.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/src/booking.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/booking.c.o -MF CMakeFiles/main.dir/src/booking.c.o.d -o CMakeFiles/main.dir/src/booking.c.o -c /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booking.c

CMakeFiles/main.dir/src/booking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/src/booking.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booking.c > CMakeFiles/main.dir/src/booking.c.i

CMakeFiles/main.dir/src/booking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/src/booking.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booking.c -o CMakeFiles/main.dir/src/booking.c.s

CMakeFiles/main.dir/src/booked.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/booked.c.o: /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booked.c
CMakeFiles/main.dir/src/booked.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/src/booked.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/src/booked.c.o -MF CMakeFiles/main.dir/src/booked.c.o.d -o CMakeFiles/main.dir/src/booked.c.o -c /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booked.c

CMakeFiles/main.dir/src/booked.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/src/booked.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booked.c > CMakeFiles/main.dir/src/booked.c.i

CMakeFiles/main.dir/src/booked.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/src/booked.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/src/booked.c -o CMakeFiles/main.dir/src/booked.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.c.o" \
"CMakeFiles/main.dir/src/Line.c.o" \
"CMakeFiles/main.dir/src/booking.c.o" \
"CMakeFiles/main.dir/src/booked.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.c.o
main: CMakeFiles/main.dir/src/Line.c.o
main: CMakeFiles/main.dir/src/booking.c.o
main: CMakeFiles/main.dir/src/booked.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build /workspaces/Data-Structures-and-Algorithms-Term-Project/airline_reservation_system/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

