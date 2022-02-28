#include <dlfcn.h>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <iostream>
#include <functional>
#include <assert.h>
//include the c++ header file that provides
//interface for all libraries
#include "mylibheader.hpp"
#define RLBOX_SINGLE_THREADED_INVOCATIONS
#ifdef USE_WASM
    // Configure RLBox for wasm sandbox
    #define RLBOX_USE_STATIC_CALLS() rlbox_wasm2c_sandbox_lookup_symbol
#else
    // Configure RLBox for noop sandbox
    #define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
#endif
#include <rlbox.hpp>

