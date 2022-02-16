
if(NOT "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitinfo.txt" IS_NEWER_THAN "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/PLSysSec/wasm2c_sandbox_compiler" "mod_wasm2c-src"
    WORKING_DIRECTORY "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/PLSysSec/wasm2c_sandbox_compiler'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout main --
  WORKING_DIRECTORY "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'main'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitinfo.txt"
    "/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/wasi-clang/rlbox_wasm2c_sandbox/build/_deps/mod_wasm2c-subbuild/mod_wasm2c-populate-prefix/src/mod_wasm2c-populate-stamp/mod_wasm2c-populate-gitclone-lastrun.txt'")
endif()

