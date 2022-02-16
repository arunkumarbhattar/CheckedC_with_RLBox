<!-- Basic Operations Example -->
## Overview  

The purpose of this example is to demonstrate the manner in which we intend to use rlbox in sandboxing untrusted functions. In contrast to rlbox's generalized usage of sandboxing the entirity of an untrusted library, we intend to sandbox only those functions of the library that are untrusted(unchecked functions in checked-c converted code).
While this very example does not use checked-c yet, it demonstrates a very high level architecture of rlbox usage.

## Description

[safe\_library.c](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/examples/legacy-c/basic_operations/safe_library.c) holds the main function that initiates the unsafe transaction through and across the rlbox boundary.

The call to [invoke\_unchecked\_function](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/baa8e83679bde092b15d6790b1fb133d3dd14767/RL-C-Prototype/examples/legacy-c/basic_operations/safe_library.c#L15) demonstrates how we invoke a rlbox interfaced function by passing the function name and arguments.

[invoke\_unchecked\_function](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/baa8e83679bde092b15d6790b1fb133d3dd14767/RL-C-Prototype/examples/legacy-c/basic_operations/safe_library.c#L15) takes care of creating the function pointer of "unsafe\_int\_pointer" from a char\* by making use of [dlsym](https://pubs.opengroup.org/onlinepubs/009695399/functions/dlsym.html).

The tainted types to each of the arguments and return value of untrusted function [unsafe\_int\_pointer](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/baa8e83679bde092b15d6790b1fb133d3dd14767/RL-C-Prototype/examples/legacy-c/basic_operations/unsafe_library.c#L17)

[invoke\_sandbox\_function\_ptr](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/baa8e83679bde092b15d6790b1fb133d3dd14767/RL-C-Prototype/rlbox_core_engine/rlbox_engine_lib_2.cpp#L170) is invoked by passing the dlsym returned function pointer, a dummy function pointer "tempptr"(_This is a hack to get around the issue of decltype unable to infer function TYPE from dlsym returned function pointer_), and the tainted arguments. Thereby, the unsafe function is executed in sandboxed memory playground and the return value is returned to t\_result (tainted type).

Now, we perform a very trivial(_just to demonstrate verify_) verification check [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/baa8e83679bde092b15d6790b1fb133d3dd14767/RL-C-Prototype/rlbox_core_engine/rlbox_engine_lib_2.cpp#L171) making use of a lambda function, following which we untaint the tainted result\_t and write it back to output argument by dereferencing the result pointer.

### Execution steps
Step 1: execute make here
Step 2: ./execute

If you intend to make some changes, all you have to do is hit make, and then run execute.
