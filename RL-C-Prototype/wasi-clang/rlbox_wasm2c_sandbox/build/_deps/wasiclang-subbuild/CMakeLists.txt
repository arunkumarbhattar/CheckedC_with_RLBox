# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(wasiclang-populate NONE)

include(ExternalProject)
ExternalProject_Add(wasiclang-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-12/wasi-sdk-12.0-linux.tar.gz"
                    SOURCE_DIR          "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src"
                    BINARY_DIR          "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/wasiclang-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
