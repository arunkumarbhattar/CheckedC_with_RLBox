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
CMAKE_SOURCE_DIR = /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build

# Include any dependencies generated for this target.
include CMakeFiles/tainted_sub_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tainted_sub_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tainted_sub_lib.dir/flags.make

CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o: CMakeFiles/tainted_sub_lib.dir/flags.make
CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o: /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp

CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp > CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.i

CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp -o CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.s

# Object files for target tainted_sub_lib
tainted_sub_lib_OBJECTS = \
"CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o"

# External object files for target tainted_sub_lib
tainted_sub_lib_EXTERNAL_OBJECTS =

libtainted_sub_lib.a: CMakeFiles/tainted_sub_lib.dir/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp.o
libtainted_sub_lib.a: CMakeFiles/tainted_sub_lib.dir/build.make
libtainted_sub_lib.a: CMakeFiles/tainted_sub_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtainted_sub_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tainted_sub_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tainted_sub_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tainted_sub_lib.dir/build: libtainted_sub_lib.a

.PHONY : CMakeFiles/tainted_sub_lib.dir/build

CMakeFiles/tainted_sub_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tainted_sub_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tainted_sub_lib.dir/clean

CMakeFiles/tainted_sub_lib.dir/depend:
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build /home/arunman_rb32/CheckedC_with_RLBox/RL-CC-Prototype/rlbox_checkedc_playground/checked_calling_unchecked/struct_marshalling_wasm/build/CMakeFiles/tainted_sub_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tainted_sub_lib.dir/depend

