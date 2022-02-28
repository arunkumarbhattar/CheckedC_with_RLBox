# About

This CheckedC version of parson is a fork of the parson JSON parsing library by kgabis (<https://github.com/kgabis/parson)>). The tests.c file that makes profuse use of the parson library has been converted to checked-c, while the parson.c and .h (library) files itself are in form of legacy-c. 

Certain calls from tests.c to the parson library have been sandboxed (Noop) in an effort to demonstrate a real-world example of CheckedC and RLbox working together.
 
DO **NOT** USE THIS CODE IN PRODUCTION. It is not kept up to date with the main parson project.

# Usage

Requires the checkedc-clang compiler (<https://github.com/Microsoft/checkedc-clang>) to build. If that is not aliased to `clang` on your system, edit the Makefile to set CC appropriately.
This also requires various RLBOX libraries which are included within this repository.

To build: `make -j4 CC=clang`

To run: `./execute`

