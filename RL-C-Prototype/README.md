<!-- Description of Directories -->
## Description Of Directories
Here you will find the description and the purpose of all the directories.

### Objects 
This directory holds all the .o and .so object files required for compilation and dynamic library linking during execution. 

### examples
This directory holds all the examples that prove various aspect of the project (CheckBox) Prototype, from supported modalities to memory partitioning capabilites

### include 
This directory holds all the dependencies for both examples and rlbox core engine

### rlbox\_core\_engine 
This directory holds all the c++ code that performs the rlbox engineering processes such as 
1.) Creating Sandbox.
2.) Tainting values.
3.) Invoking Unsafe functions in a sandbox.
4.) Untainting the received values from sandbox after appropriate verification.
5.) Returning expected values from unsafe\_library's callee back to the safe\_library's function caller.
