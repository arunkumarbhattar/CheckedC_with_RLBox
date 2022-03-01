.PHONY: hello clean
INC =-I ../../rlbox/
ENG_DIR = ../../../RL-C-Prototype/rlbox_core_engine
OBJ_DIR = ../../../RL-C-Prototype/Objects
UNSAFE_LIB_DIR = ../../../RL-C-Prototype/include/library_3
WASMRT_DIR = -I ../../wasmrt
WASMRT = ../../wasmrt

hello: $(ENG_DIR)/rlbox_engine_main.cpp safe_library.c  $(UNSAFE_LIB_DIR)/lib.c $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp 
	$(CC) -g -c -Wall $(UNSAFE_LIB_DIR)/lib.c -o $(OBJ_DIR)/unsafe_lib.o
	$(CC) -g -c -Wall $(UNSAFE_LIB_DIR)/wasm_c_definitions/lib_wasm.c $(UNSAFE_LIB_DIR)/wasm_c_definitions/ $(WASMRT_DIR) -o $(OBJ_DIR)/unsafe_lib_wasm.o
	$(CC) -g -c -Wall safe_library.c -o $(OBJ_DIR)/safe_lib_wasm.o
	$(CC) -g -std=c++17 -c -Wall -DUSE_WASM $(INC) $(WASMRT_DIR) $(OBJ_DIR)/unsafe_lib_wasm.o $(ENG_DIR)/rlbox_engine_main.cpp  -o $(OBJ_DIR)/rlbox_eng.o
	$(CC) -g -std=c++17 -c -Wall $(INC) $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp -o $(OBJ_DIR)/tainted_sub_func_lib3.o
	clang++ -g  -Wall $(OBJ_DIR)/safe_lib.o $(OBJ_DIR)/unsafe_lib.o $(OBJ_DIR)/unsafe_lib_wasm.o $(OBJ_DIR)/tainted_sub_func_lib3.o $(OBJ_DIR)/rlbox_eng.o -o execute -ldl

clean:
	-rm execute
