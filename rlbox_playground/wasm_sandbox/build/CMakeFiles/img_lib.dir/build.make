# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build

# Include any dependencies generated for this target.
include CMakeFiles/img_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/img_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/img_lib.dir/flags.make

CMakeFiles/img_lib.dir/library/lib.c.o: CMakeFiles/img_lib.dir/flags.make
CMakeFiles/img_lib.dir/library/lib.c.o: ../library/lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/img_lib.dir/library/lib.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/img_lib.dir/library/lib.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/library/lib.c

CMakeFiles/img_lib.dir/library/lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/img_lib.dir/library/lib.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/library/lib.c > CMakeFiles/img_lib.dir/library/lib.c.i

CMakeFiles/img_lib.dir/library/lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/img_lib.dir/library/lib.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/library/lib.c -o CMakeFiles/img_lib.dir/library/lib.c.s

# Object files for target img_lib
img_lib_OBJECTS = \
"CMakeFiles/img_lib.dir/library/lib.c.o"

# External object files for target img_lib
img_lib_EXTERNAL_OBJECTS =

libimg_lib.a: CMakeFiles/img_lib.dir/library/lib.c.o
libimg_lib.a: CMakeFiles/img_lib.dir/build.make
libimg_lib.a: CMakeFiles/img_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libimg_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/img_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/img_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/img_lib.dir/build: libimg_lib.a

.PHONY : CMakeFiles/img_lib.dir/build

CMakeFiles/img_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/img_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/img_lib.dir/clean

CMakeFiles/img_lib.dir/depend:
	cd /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build /home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/CMakeFiles/img_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/img_lib.dir/depend

