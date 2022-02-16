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

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)

#### Building
###### TEST CASE STEP
uncomment the code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/699259f34168a88d4dbb45e2ea7352d7aae820bc/rlbox_playground/wasm_sandbox/solution.cpp#L150)

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
==263448==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x5555555d7b8c bp 0x7fffffffd830 sp 0x7fffffffc960 T0)
==263448==The signal is caused by a READ memory access.
==263448==Hint: address points to the zero page.
```

**Expectation: The host and sandbox should error out and exit.**

### Sandbox error

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)
 
###### TEST CASE STEP
uncomment the code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/699259f34168a88d4dbb45e2ea7352d7aae820bc/rlbox_playground/wasm_sandbox/library/lib.c#L15)

#### Building

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
.................................
.................................
Image parsing: 98 out of 100
Image parsing: 99 out of 100
Image parsing: 100 out of 100
Image pixels: 
2 2 2 2 2 2 2 2 2 2 

```

**Expectation: The host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**

#### Observation

```
Even with a crash an obvious crash in the sandboxed code, the crashed never takes place, and for some reason, the subsequent printf also does not occur. 
But further computations are performed correctly. 

What happens to the host when a memory error (e.g., segfault/null-ptr dereference) occurs in the sandbox?
 1   const char *s = NULL;
 2  printf( "%c\n", s[0] );
 3   /**/
 4   printf("Post Crash Prints \n");
 5   ImageHeader* header = (ImageHeader*) malloc(sizeof(ImageHeader));
 6   header->status_code = 0;
 7   header->width = 10;
 8   header->height = 1;

even after crash at (2), assignments at line (7) and (8) are perfectly passed out of the sandboxed code. However, harmless line (4) is not executed.
```
### Sandbox host memory access

What happens to the sandbox when it tries to access host memory?

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)

###### TEST CASE STEP
uncomment the code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/699259f34168a88d4dbb45e2ea7352d7aae820bc/rlbox_playground/wasm_sandbox/library/lib.c#L27)

#### Building
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
#### Running/Observation

```
root@c3a679ea99b1:/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox# cmake --build ./build --target run_solution
[ 18%] Built target img_lib
[ 81%] Built target img_lib_wasm
[100%] Built target img_app_solution
Scanning dependencies of target run_solution
Pre library crash Prints 
AddressSanitizer:DEADLYSIGNAL
=================================================================
==265469==ERROR: AddressSanitizer: SEGV on unknown address 0x7ffdffffc8f0 (pc 0x555555627a21 bp 0x7fffffffc520 sp 0x7fffffffc4f0 T0)
==265469==The signal is caused by a WRITE memory access.
    #0 0x555555627a20 in i32_store (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0xd3a20)
    #1 0x555555628aa6 in w2c_parse_image_header (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0xd4aa6)
    #2 0x5555555ddc90 in auto rlbox::rlbox_wasm2c_sandbox::impl_invoke_with_func_ptr<ImageHeader* (char*, char*), unsigned int (unsigned int, unsigned int), unsigned int, unsigned int>(unsigned int (*)(unsigned int, unsigned int), unsigned int&&, unsigned int&&) (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x89c90)
    #3 0x5555555de0f6 in auto rlbox::rlbox_sandbox<rlbox::rlbox_wasm2c_sandbox>::INTERNAL_invoke_with_func_ptr<ImageHeader* (char*, char*), rlbox::tainted<char*, rlbox::rlbox_wasm2c_sandbox>&, rlbox::tainted<char*, rlbox::rlbox_wasm2c_sandbox>&>(char const*, void*, rlbox::tainted<char*, rlbox::rlbox_wasm2c_sandbox>&, rlbox::tainted<char*, rlbox::rlbox_wasm2c_sandbox>&) (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x8a0f6)
    #4 0x5555555d7881 in main (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x83881)
    #5 0x7ffff67080b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
    #6 0x5555555d6d8d in _start (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0x82d8d)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (/home/arunman_rb32/CheckedC_with_RLBox/rlbox_playground/wasm_sandbox/build/img_app_solution+0xd3a20) in i32_store
==265469==ABORTING

```
**Expectation: The sandbox should error out (e.g., segfault), the host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**

### Host Sandbox memory access
What happens to the host when it tries to access the memory that belongs to the sandbox?

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)

###### TEST CASE STEP
Check this line of code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/c4c4181cf80ef550ff6f0cbf2faf32d909f48ebb/rlbox_playground/wasm_sandbox/solution.cpp#L193)

#### Building

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
.................
.................
Image parsing: 87 out of 100
Image parsing: 88 out of 100
Image parsing: 89 out of 100
Image parsing: 90 out of 100
Image parsing: 91 out of 100
Image parsing: 92 out of 100
Image parsing: 93 out of 100
Image parsing: 94 out of 100
Image parsing: 95 out of 100
Image parsing: 96 out of 100
Image parsing: 97 out of 100
Image parsing: 98 out of 100
Image parsing: 99 out of 100
Image parsing: 100 out of 100
Image pixels: 
2 2 2 2 2 2 2 2 2 2 

```

**Expectation: This is expected behavior. Nothing should happen to the host or sandbox.**

**Observation:
It it not possible to get an address pointing to the sandboxed region. 
The tainted types are explicitly written just with an intent to hold values when used in sandbox, but not give out information on where exactly it is in the sandbox.
However, normal usage to retrieve value from the tainted type post appropriate verification is very much valid.
This is what happens when you try to apply & on a tainted type and then perform verification to get the address -->
rlbox.hpp:74:21: error: static assertion failed: unverified_safe_because does not support pointers.

### Use-after-free through sandbox

What happens to the host when it tries to access the memory that belongs to the sandbox after it is freed by the sandbox?

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/rlbox_playground/struct_marshalling)

###### TEST CASE STEP
uncomment the code [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/c4c4181cf80ef550ff6f0cbf2faf32d909f48ebb/rlbox_playground/wasm_sandbox/solution.cpp#L200)

#### Building

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
Output --> 

```
...................
...................
Image parsing: 95 out of 100
Image parsing: 96 out of 100
Image parsing: 97 out of 100
Image parsing: 98 out of 100
Image parsing: 99 out of 100
Image parsing: 100 out of 100
Image pixels: 
2 2 2 2 2 2 2 2 2 2 

Post Freed Sandbox memory is operated opon to produce the value: 60288 
[100%] Built target run_solution
```

**Expectation: ..need to figure out..**
**Observation**
Random junk values are being computed and returned.

