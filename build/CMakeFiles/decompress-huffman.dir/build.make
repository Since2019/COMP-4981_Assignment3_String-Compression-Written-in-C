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
CMAKE_SOURCE_DIR = "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build"

# Include any dependencies generated for this target.
include CMakeFiles/decompress-huffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/decompress-huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/decompress-huffman.dir/flags.make

CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o: CMakeFiles/decompress-huffman.dir/flags.make
CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o: ../decompress-huffman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o -c "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-huffman.c"

CMakeFiles/decompress-huffman.dir/decompress-huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decompress-huffman.dir/decompress-huffman.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-huffman.c" > CMakeFiles/decompress-huffman.dir/decompress-huffman.c.i

CMakeFiles/decompress-huffman.dir/decompress-huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decompress-huffman.dir/decompress-huffman.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-huffman.c" -o CMakeFiles/decompress-huffman.dir/decompress-huffman.c.s

# Object files for target decompress-huffman
decompress__huffman_OBJECTS = \
"CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o"

# External object files for target decompress-huffman
decompress__huffman_EXTERNAL_OBJECTS =

decompress-huffman: CMakeFiles/decompress-huffman.dir/decompress-huffman.c.o
decompress-huffman: CMakeFiles/decompress-huffman.dir/build.make
decompress-huffman: CMakeFiles/decompress-huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable decompress-huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decompress-huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/decompress-huffman.dir/build: decompress-huffman

.PHONY : CMakeFiles/decompress-huffman.dir/build

CMakeFiles/decompress-huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/decompress-huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/decompress-huffman.dir/clean

CMakeFiles/decompress-huffman.dir/depend:
	cd "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles/decompress-huffman.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/decompress-huffman.dir/depend

