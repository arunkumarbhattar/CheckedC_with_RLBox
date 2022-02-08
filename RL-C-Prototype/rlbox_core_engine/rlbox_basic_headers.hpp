#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
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
#include <rlbox.hpp>
#include <rlbox_noop_sandbox.hpp>
