# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(mod_wasm2c-populate NONE)

include(ExternalProject)
ExternalProject_Add(mod_wasm2c-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/PLSysSec/wasm2c_sandbox_compiler" "GIT_TAG" "main"
                    SOURCE_DIR          "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src"
                    BINARY_DIR          "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
