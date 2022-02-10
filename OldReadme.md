<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

Firstly, you have to clone, compile and build a Checked-C Clang compiler.
This modified clang compiler will be used to compile Checked C annotated code.

Please refer to [https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/Setup-and-Build.md](https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/Setup-and-Build.md) to build your Checked-C capable Clang Compiler.

Secondly (NOT MANDATORY), you might want to install the 3c tool which would allow for a semi-automatic convertion of legacy-C code to Checked-C code.

Please refer to [https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/3C/INSTALL.md](https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/3C/INSTALL.md) to build your 3C tool.

(NOT MANDATORY) Now if you have a large legacy-C codebase you want to convert to checked-C, you would want to generate a one-stop-shop script that would take your codebase's compile\_commands.json file and generate you a convert\_all.sh script file. Just executing this one command will run 3C tool recursively directory to directory and file to file (C) dictated by your compile\_commands.json. 

Please refer to [https://github.com/correctcomputation/checkedc-clang/tree/main/clang/tools/3c/utils](https://github.com/correctcomputation/checkedc-clang/tree/main/clang/tools/3c/utils)

If your project does NOT contain a compile\_commands.json, you would typically make use of the **bear** utility to generate compile\_commands.json from the **Makefile**. However, if that bear does not work well, you can use **compile\_db** command. 

Please refer to [https://github.com/nickdiego/compiledb](https://github.com/nickdiego/compiledb) 

### LEGACY-C EXAMPLES

### Basic Operations -->
This example intends to use RLBOX as a mechanism to call unsafe/untrusted/unchecked functions from safe/trusted/checked functions.

[Example Directory](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-C-Prototype/examples/legacy-c/basic_operations)

#### Overview:
[Safe Library](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/examples/legacy-c/basic_operations/safe_library.c)'s main()
attempts to call unsafe function [unsafe\_int\_pointer][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/examples/legacy-c/basic_operations/unsafe_library.c#L17] through a RLBOX interface API [invoke\_unchecked\_function][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L110].

This very function takes care of all the dirty work of creating a RL-sandbox, creating tainted types, calling the unchecked/unsafe/untrusted function, followed by untainting the returned values after appropriate verification and then assigning the untainted(unwrapped) result back to the result argument. 

The function [unsafe\_char\_pointer][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/examples/legacy-c/basic_operations/unsafe_library.c#L25] also is called through its sandboxed interface API [invoke\_unchecked\_print\_function][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L119].

For more instructions on how to simulate this, please refer to README [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/examples/legacy-c/basic_operations/README.md)

### Struct Marshalling -->
This examples takes the above approach of uncapsulating unsafe functions within RLBOX sandbox a step higher and attempts to showcase more capabilities of the concept of RLBOX encapsulation.
This example showcases the capabilities of this concept on more of an engineering standpoint as compared to the theoretical end.

This [Project](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-C-Prototype/examples/legacy-c/struct_marshalling) aims to practicalize (through code example) the below engineering capabilities -->

1.) Parsing structs to/from a sandbox
	* Defining structs in a manner that RLBOX Sandbox understands them [lib\_struct\_file.h](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/include/library_3/lib_struct_file.h).
	* Loading structs into the RLBOX\_ENGINE [rlbox\_load\_structs\_from\_library](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L29) 

2.) Receiving and Handling a struct pointer [header](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L54)

3.) Sandboxing a function that accepts a function pointer as an argument. [check\_here][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L89] 
  