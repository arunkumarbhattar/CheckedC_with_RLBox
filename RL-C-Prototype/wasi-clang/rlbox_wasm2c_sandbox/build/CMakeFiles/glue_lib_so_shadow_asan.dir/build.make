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
CMAKE_SOURCE_DIR = /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build

# Include any dependencies generated for this target.
include CMakeFiles/glue_lib_so_shadow_asan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glue_lib_so_shadow_asan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make

wasm/glue_lib_wasm2c.h: ../c_src/wasm2c_sandbox_wrapper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building wasm2c compiler, runtime and wasm sandboxed library"
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src && /usr/bin/cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS="" -DCMAKE_CXX_FLAGS="" -DLINK_FLAGS="" -S . -B ./build
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src && /usr/bin/cmake --build ./build --config Release --parallel
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src && /usr/bin/cmake -E make_directory /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm/
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src && /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/clang --sysroot /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/share/wasi-sysroot/ -O3 -Wl,--export-all -Wl,--no-entry -Wl,--growable-table -Wl,--stack-first -Wl,-z,stack-size=1048576 -o /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm//glue_lib_wasm2c.wasm /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/c_src/wasm2c_sandbox_wrapper.c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/rlbox-src/code/tests/rlbox_glue/lib/libtest.c
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src && /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/bin//wasm2c -o /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm//glue_lib_wasm2c.c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm//glue_lib_wasm2c.wasm

wasm/glue_lib_wasm2c.c: wasm/glue_lib_wasm2c.h
	@$(CMAKE_COMMAND) -E touch_nocreate wasm/glue_lib_wasm2c.c

wasm/glue_lib_wasm2c.wasm: wasm/glue_lib_wasm2c.h
	@$(CMAKE_COMMAND) -E touch_nocreate wasm/glue_lib_wasm2c.wasm

CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o: wasm/glue_lib_wasm2c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm/glue_lib_wasm2c.c

CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm/glue_lib_wasm2c.c > CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/wasm/glue_lib_wasm2c.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o   -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.s

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o: CMakeFiles/glue_lib_so_shadow_asan.dir/flags.make
CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o: _deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o -c /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp > CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.i

CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp -o CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.s

# Object files for target glue_lib_so_shadow_asan
glue_lib_so_shadow_asan_OBJECTS = \
"CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o" \
"CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o"

# External object files for target glue_lib_so_shadow_asan
glue_lib_so_shadow_asan_EXTERNAL_OBJECTS =

libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/wasm/glue_lib_wasm2c.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-impl.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-unix.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-os-win.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-runner.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-wasi.c.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/_deps/mod_wasm2c-src/wasm2c/wasm-rt-shadow.cpp.o
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/build.make
libglue_lib_so_shadow_asan.so: CMakeFiles/glue_lib_so_shadow_asan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library libglue_lib_so_shadow_asan.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glue_lib_so_shadow_asan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glue_lib_so_shadow_asan.dir/build: libglue_lib_so_shadow_asan.so

.PHONY : CMakeFiles/glue_lib_so_shadow_asan.dir/build

CMakeFiles/glue_lib_so_shadow_asan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glue_lib_so_shadow_asan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glue_lib_so_shadow_asan.dir/clean

CMakeFiles/glue_lib_so_shadow_asan.dir/depend: wasm/glue_lib_wasm2c.h
CMakeFiles/glue_lib_so_shadow_asan.dir/depend: wasm/glue_lib_wasm2c.c
CMakeFiles/glue_lib_so_shadow_asan.dir/depend: wasm/glue_lib_wasm2c.wasm
	cd /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/CMakeFiles/glue_lib_so_shadow_asan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glue_lib_so_shadow_asan.dir/depend

