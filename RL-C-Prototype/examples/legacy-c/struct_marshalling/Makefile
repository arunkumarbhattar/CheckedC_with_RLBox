.PHONY: hello clean
INC =-I ../../../include/rlbox/code/include
ENG_DIR = ../../../rlbox_core_engine
OBJ_DIR = ../../../Objects
CUR_OBJ_DIR = Objects
UNSAFE_LIB_DIR = ../../../include/library_3

hello: $(ENG_DIR)/rlbox_engine_main.cpp safe_library.c  $(UNSAFE_LIB_DIR)/lib.c $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp 
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) $(ENG_DIR)/rlbox_engine_main.cpp -o $(OBJ_DIR)/rlbox_eng.o
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) $(UNSAFE_LIB_DIR)/tainted_sub_functions.cpp -o $(OBJ_DIR)/tainted_sub_func_lib3.o
	clang -g $(CFLAGS) -c -Wall safe_library.c -o safe_lib.o
	clang -g $(CFLAGS) -c -Wall $(UNSAFE_LIB_DIR)/lib.c -o $(OBJ_DIR)/unsafe_lib.o
	clang++ -g $(CFLAGS) -Wall $(OBJ_DIR)/rlbox_eng.o $(OBJ_DIR)/tainted_sub_func_lib3.o safe_lib.o $(OBJ_DIR)/unsafe_lib.o -o execute -ldl

clean:
	-rm hello
