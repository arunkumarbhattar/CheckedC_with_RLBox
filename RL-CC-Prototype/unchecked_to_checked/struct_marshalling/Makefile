.PHONY: hello clean
INC =-I ../../../RL-C-Prototype/include/rlbox/code/include/
ENG_DIR = ../../../RL-C-Prototype/rlbox_core_engine
OBJ_DIR = ../../../RL-C-Prototype/Objects/
UNSAFE_LIB_DIR = ../../checked_c_library/library_3/

hello: $(ENG_DIR)/rlbox_engine_main.cpp safe_library.c  $(UNSAFE_LIB_DIR)/lib.c $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp 
	$(CC) -g -std=c++17 -c -Wall $(INC) $(ENG_DIR)/rlbox_engine_main.cpp -o $(OBJ_DIR)/rlbox_eng.o
	$(CC) -g -std=c++17 -c -Wall $(INC) $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp -o $(OBJ_DIR)/tainted_sub_func_lib3.o
	$(CC) -g -c -Wall safe_library.c -o safe_lib.o
	$(CC) -g -c -Wall $(UNSAFE_LIB_DIR)/lib.c -o $(OBJ_DIR)/unsafe_lib.o
	clang++ -g  -Wall $(OBJ_DIR)/rlbox_eng.o $(OBJ_DIR)/tainted_sub_func_lib3.o safe_lib.o $(OBJ_DIR)/unsafe_lib.o -o execute -ldl

clean:
	-rm hello
