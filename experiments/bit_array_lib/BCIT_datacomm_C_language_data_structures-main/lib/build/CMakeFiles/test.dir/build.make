# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/619/bin/cmake

# The command to remove a file.
RM = /snap/cmake/619/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build"

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.c.o: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test.dir/test.c.o -c "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/test.c"

CMakeFiles/test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/test.c" > CMakeFiles/test.dir/test.c.i

CMakeFiles/test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/test.c" -o CMakeFiles/test.dir/test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/test.c.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/bit_array_lib/BCIT_datacomm_C_language_data_structures-main/lib/build/CMakeFiles/test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

