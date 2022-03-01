cmake_minimum_required(VERSION 3.13)

project(simple_library_example
        VERSION 0.1
        DESCRIPTION "An example application that simulates a typical image parsing program")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIB_3_PATH "../../../../RL-C-Prototype/include/library_3")
set(WASM_C_DEFINITIONS "../../../../RL-C-Prototype/include/library_3/wasm_c_definitions")
set(WASM_RT_PATH "../../../dependencies/wasmrt/")
set(RLBOX_CODE_PATH "../../../dependencies/rlbox/")
set(RLBOX_ENG_PATH "../../../../RL-C-Prototype/rlbox_core_engine")
#this is to compile the lib.c library and generate img_lib
add_library(img_lib STATIC "${LIB_3_PATH}/lib.c")
target_include_directories(img_lib PUBLIC "${LIB_3_PATH}")

#this is to compile the lib_wasm.c library and generate img_lib_wasm
file(GLOB WASM_RT "${CMAKE_SOURCE_DIR}../../wasmrt/*.c")

add_library(img_lib_wasm STATIC ${WASM_RT} "${WASM_C_DEFINITIONS}/lib_wasm.c")
target_include_directories(img_lib_wasm PUBLIC "${WASM_C_DEFINITIONS}"
	"${RLBOX_CODE_PATH}"
	"${WASM_RT_PATH}")


add_library(tainted_sub_lib STATIC "${LIB_3_PATH}/tainted_sub_functions.cpp")
target_include_directories(tainted_sub_lib PUBLIC "${LIB_3_PATH}"
	"${RLBOX_CODE_PATH}"
					  )
				 
############################

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-comment)
endif()

add_library(img_final STATIC "safe_library.c")

#this is to compile rlbox_engine_main.cpp
add_executable (img_app_solution "${RLBOX_ENG_PATH}/rlbox_engine_main.cpp")
target_include_directories(img_app_solution PUBLIC "${RLBOX_CODE_PATH}"
                                          "${WASM_C_DEFINITIONS}/"
					  "${LIB_3_PATH}/lib.c"
					  "${LIB_3_PATH}/tainted_sub_functions.cpp")
target_link_libraries(img_app_solution tainted_sub_lib img_lib img_lib_wasm img_final)				  

add_custom_target(run_solution COMMAND $<TARGET_FILE:img_app_solution>)
add_dependencies(run_solution img_app_solution)
