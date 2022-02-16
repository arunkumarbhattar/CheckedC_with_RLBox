<!-- Basic Operations Example -->
## Overview  

The purpose of this example is to demonstrate 
1.) Sandboxing multiple functions calls within a single sandbox.
2.) Marshalling structs across the sandbox boundary
3.) Sandboxing functions that accept function pointers as arguments.

## Description

A single global sandbox is created at the start of the program execution [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/examples/legacy-c/struct_marshalling/safe_library.c#L32)

[get\_image\_bytes](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/examples/legacy-c/struct_marshalling/safe_library.c#L40) is used to write some valid information into the char\* buffer allocated in the trusted region.

[invoke\_unchecked\_image\_load](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/examples/legacy-c/struct_marshalling/safe_library.c#L41) is the call to the rlbox interface function wherein, calls to untrusted functions, tainting, untainting and verification is done.

Struct marshalling requires defining structs in a manner in which rlbox can understand. This is done [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L4) 
Finally defined structs must be [loaded](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L16) before they can be used.

Call to the untrusted function [parse\_image\_header](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L43) is done here. 
Within this function, since we are passing a tainted pointer, we can try different pointer attack techniques such as 
1.) Freeing received pointer here 

2.) Changing pointer to point to a different address (although this needs a double pointer argument).

3.) Writing illegal values into the pointer here.

[this](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L46) is call to another untrusted function.

[sandboxed\_image\_parsing\_progress](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/include/library_3/tainted_sub_functions.cpp#L4) is a rlbox interface to the function [image\_parsing\_progress](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/include/library_3/lib.c#L31).
The reason why we do this is because, as we know, sandbox can only accept constant literals or tainted types as arguments. Thus, the function pointer that is being attempted to be passed must also accept and return tainted types.

This sandboxed function callback is registered [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L64) and the this very callback is passed as an argument function pointer to the sandboxed call to untrusted function [parse\_image\_body](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/b534374f9075d8e95bf3522e8aa6d6d275d54d5a/RL-C-Prototype/include/library_3/lib.c#L19)

Finally the trusted function [print\_output\_stream](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/c3118e53c4167a18a1d4b5ff0789c8b90a3539fb/RL-C-Prototype/examples/legacy-c/struct_marshalling/safe_library.c#L13) is sandboxed (_just to show that it can be done_) and the characters are printed to the output.

### Execution steps
Step 1: execute make here
Step 2: ./execute

After you make changes in this playground, all you have to do is hit make, and then run execute.
