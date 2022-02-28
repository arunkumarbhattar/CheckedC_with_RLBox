#pragma once 
#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#define RLBOX_SINGLE_THREADED_INVOCATIONS

#ifdef USE_WASM
    // Configure RLBox for wasm sandbox
    #define RLBOX_USE_STATIC_CALLS() rlbox_wasm2c_sandbox_lookup_symbol
    #include <rlbox.hpp>
    #include "./wasm_c_definitions/lib_wasm.h"
    #include <rlbox_wasm2c_sandbox.hpp>
    using sandbox_type_t = rlbox::rlbox_wasm2c_sandbox;
#else
    // Configure RLBox for noop sandbox
    #define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
    #include <rlbox.hpp>
    #include <rlbox_noop_sandbox.hpp>
    using sandbox_type_t = rlbox::rlbox_noop_sandbox;
#endif


template<typename T>
using tainted_img = rlbox::tainted<T, sandbox_type_t>;

void sandboxed_image_parsing_progress(rlbox::rlbox_sandbox<sandbox_type_t>& sandbox, tainted_img<unsigned int> progress);
