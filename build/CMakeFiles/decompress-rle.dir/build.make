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
include CMakeFiles/decompress-rle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/decompress-rle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/decompress-rle.dir/flags.make

CMakeFiles/decompress-rle.dir/decompress-rle.c.o: CMakeFiles/decompress-rle.dir/flags.make
CMakeFiles/decompress-rle.dir/decompress-rle.c.o: ../decompress-rle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/decompress-rle.dir/decompress-rle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decompress-rle.dir/decompress-rle.c.o -c "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-rle.c"

CMakeFiles/decompress-rle.dir/decompress-rle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decompress-rle.dir/decompress-rle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-rle.c" > CMakeFiles/decompress-rle.dir/decompress-rle.c.i

CMakeFiles/decompress-rle.dir/decompress-rle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decompress-rle.dir/decompress-rle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/decompress-rle.c" -o CMakeFiles/decompress-rle.dir/decompress-rle.c.s

# Object files for target decompress-rle
decompress__rle_OBJECTS = \
"CMakeFiles/decompress-rle.dir/decompress-rle.c.o"

# External object files for target decompress-rle
decompress__rle_EXTERNAL_OBJECTS =

decompress-rle: CMakeFiles/decompress-rle.dir/decompress-rle.c.o
decompress-rle: CMakeFiles/decompress-rle.dir/build.make
decompress-rle: CMakeFiles/decompress-rle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable decompress-rle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decompress-rle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/decompress-rle.dir/build: decompress-rle

.PHONY : CMakeFiles/decompress-rle.dir/build

CMakeFiles/decompress-rle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/decompress-rle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/decompress-rle.dir/clean

CMakeFiles/decompress-rle.dir/depend:
	cd "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build" "/home/judao/BCIT/NetWrokApp/Assignment3 String Compression/COMP-4981_Assignment3_String-Compression-Written-in-C/build/CMakeFiles/decompress-rle.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/decompress-rle.dir/depend

