#pragma once 
#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <rlbox.hpp>
#include <rlbox_noop_sandbox.hpp>

using namespace rlbox;

using rlbox_sandbox_t = rlbox::rlbox_noop_sandbox;

template<typename T>
using tainted_img = tainted<T, rlbox_sandbox_t>;

void sandboxed_image_parsing_progress(rlbox_sandbox<rlbox_sandbox_t>& sandbox, tainted_img<unsigned int> progress);
