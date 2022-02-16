.PHONY: hello clean
INC =-I ../../RL-C-Prototype/include/rlbox/code/include/
ENG_DIR = ../../RL-C-Prototype/rlbox_core_engine
OBJ_DIR = ../../RL-C-Prototype/Objects/

execute: $(ENG_DIR)/rlbox_engine_lib_2.cpp safe_library.c  unsafe_library.c 
	clang -fPIC -shared unsafe_library.c -o $(OBJ_DIR)/unsafe_lib.so 
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) $(ENG_DIR)/rlbox_engine_lib_2.cpp -o $(OBJ_DIR)/rlbox_eng.o
	clang -g $(CFLAGS) -c -Wall safe_library.c -o $(OBJ_DIR)/safe_lib_1.o
	clang -g $(CFLAGS) -c -Wall unsafe_library.c -o $(OBJ_DIR)/unsafe_lib_1.o
	clang++ -g $(CFLAGS) -Wall $(OBJ_DIR)/rlbox_eng.o $(OBJ_DIR)/safe_lib_1.o $(OBJ_DIR)/unsafe_lib_1.o -o execute -ldl

clean:
	-rm execute
