# RLBox Playground

This folder contains examples demonstrating various capabilities of RLBox sandbox that are relevant to the project.


### Setup
Setup instructions..

We will require wasm based clang, wasm2c binaries in one of our examples below. 
Hence please make sure to do --> 
```
git submodule init
git submodule update --force --recursive --init --remote
```

### Terminology
* Host: The unsandboxed code.

* Sandboxed/Sandbox: The functions within a sandbox.

## Demonstrative examples

These examples demonstrate basic functionalities of RLBox.

### Simple sandbox
This example demonstrates how to call a function inside sandbox using  different types of arguments:

* Pointer to scalar types (e.g., int *, char *, etc)

> Folder: [basic\_operations](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/basic_operations)

#### Description of this example 
[description](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/rlbox_playground/basic_operations/README.md)

#### Building

Step 1: Execute make in the above directory
```
make
```
#### Running

Step 1: Execute the executable "execute"
```
./execute
```

### Sandbox calling host
This example demonstrates how a function inside sandbox can call a function in the host using different types of arguments:

* Scalar types (e.g., `int`, `char`, etc).
* Pointer to scalar types (e.g., `int *`, `char *`, etc)
* Pointer to structure types (e.g., `struct foo*`, etc) 

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)

#### Description of this example 
[description](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/rlbox_playground/struct_marshalling/README.md)

#### Building

Step 1: Execute make in the above directory
```
make
```

#### Running

Step 1: Execute the executable "execute"
```
./execute
```

## Capabilities examples

The following examples demonstrate possible error cases in host and sandbox and how RLBox handles these cases.

### Host error

What happens to the sandbox when a memory error (e.g., segfault/null-ptr dereference) occurs in the host?

> Folder:

#### Building
###### TEST CASE STEP
uncomment the code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/7becafc4e0c0d0d22b6a8c5bc158ef2760eee301/rlbox_playground/wasm_sandbox/solution.cpp#L134)
```
STEP 1: Compile your library files (lib.c in our case), to a .wasm file. PFB commands:

```
cd wasm_sandbox/library/
make
```
STEP 2: Now that you see a lib.wasm binary file, you would want to convert this into .c and .h files that hold defintions for all the sandbox shadow memory operations that are taking place. PFB commands:

```
cp lib.wasm ../wasm_readable_definitions/
```
STEP 3: Use the wasm2c executable to convert your generated .wasm file to .c and .h file. 

```
cd ../wasm_readable_definitions
wasm2c -o lib_wasm.c lib.wasm
```
STEP 4: Build the whole project 

```
cd ..
rm -rf build
cmake -S ./ -B ./build
cmake --build ./build --parallel
```

#### Running

```
root@c3a679ea99b1:/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox# cmake --build ./build --target run_solution
[ 63%] Built target img_lib_wasm
[ 81%] Built target img_lib
Scanning dependencies of target img_app_solution
[ 90%] Building CXX object CMakeFiles/img_app_solution.dir/solution.cpp.o
[100%] Linking CXX executable img_app_solution
[100%] Built target img_app_solution
/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/solution.cpp:136:16: runtime error: load of null pointer of type 'const char'
AddressSanitizer:DEADLYSIGNAL
=================================================================
==263448==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x5555555d7b8c bp 0x7fffffffd830 sp 0x7fffffffc960 T0)
==263448==The signal is caused by a READ memory access.
==263448==Hint: address points to the zero page.
    #0 0x5555555d7b8b in main (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x83b8b)
    #1 0x7ffff68570b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
    #2 0x5555555d6d6d in _start (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x82d6d)
```

**Expectation: The host and sandbox should error out and exit.**

### Sandbox error

What happens to the host when a memory error (e.g., segfault/null-ptr dereference) occurs in the sandbox?

> Folder:

#### Building
WARNING: The building of this example makes use of the executables --> clang, wasm-ld and wasm2c --> These are built from the repository --> https://github.com/PLSysSec/wasm2c_sandbox_compiler. 

THIS EXAMPLE makes use of pre-built binaries, hence everything interlocks and works well together. 
However, Should you want to build the aforementioned executables by yourself, be sure to also update the contents of https://github.com/PLSysSec/simple_library_example/tree/secdev2021/wasmrt into the directory wasmrt. Just so that there in sync with their most recent versions.

STEP 1: Compile your library files (lib.c in our case), to a .wasm file. PFB commands:

```
cd wasm_sandbox/library/
make
```
STEP 2: Now that you see a lib.wasm binary file, you would want to convert this into .c and .h files that hold defintions for all the sandbox shadow memory operations that are taking place. PFB commands:

```
cp lib.wasm ../wasm_readable_definitions/
```
STEP 3: Use the wasm2c executable to convert your generated .wasm file to .c and .h file. 

```
cd ../wasm_readable_definitions
wasm2c -o lib_wasm.c lib.wasm
```
STEP 4: Build the whole project 

```
cd ..
rm -rf build
cmake -S ./ -B ./build
cmake --build ./build --parallel
```

#### Running

```
cmake --build ./build --target run_solution

```

**Expectation: The host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**
### Sandbox host memory access

What happens to the sandbox when it tries to access host memory?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: The sandbox should error out (e.g., segfault), the host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**
### Host Sandbox memory access

What happens to the host when it tries to access the memory that belongs to the sandbox?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: This is expected behavior. Nothing should happen to the host or sandbox.**
### Use-after-free through sandbox

What happens to the host when it tries to access the memory that belongs to the sandbox after it is freed by the sandbox?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: ..need to figure out..**
