.PHONY: hello clean
INC =-I ../../../include/rlbox/code/include
ENG_DIR = ../../../rlbox_core_engine
OBJ_DIR = ../../../Objects
CUR_OBJ_DIR = Objects

hello: $(ENG_DIR)/rlbox_engine_main.cpp safe_library.c  unsafe_library.c 
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) $(ENG_DIR)/rlbox_engine_main.cpp -o $(OBJ_DIR)/rlbox_eng.o
	clang -g $(CFLAGS) -c -Wall safe_library.c -o safe_lib.o
	clang -g $(CFLAGS) -c -Wall unsafe_library.c -o unsafe_lib.o
	clang++ -g $(CFLAGS) -Wall $(OBJ_DIR)/rlbox_eng.o safe_lib.o unsafe_lib.o -o execute -ldl

clean:
	-rm hello
