CC = clang
CFLAGS = -O0 -g -Wall -Wextra -std=c99 -pedantic-errors
RLB_INC =-I ../../../RL-C-Prototype/include/rlbox/code/include
OBJ_DIR = ../../../RL-C-Prototype/Objects

all: test

.PHONY: compile test
test: tests.c parson.c
	clang-12 -g -std=c++17 -c -Wall $(RLB_INC) rlbox_engine_main.cpp -o $(OBJ_DIR)/prlbox_eng.o
	$(CC) -g -c -Wall parson.c -o $(OBJ_DIR)/parson_lib.o
	$(CC) -g -c -Wall tests.c -o $(OBJ_DIR)/tests.o
	clang++ -g -Wall $(OBJ_DIR)/prlbox_eng.o $(OBJ_DIR)/tests.o $(OBJ_DIR)/parson_lib.o -o execute -ldl

compile:
	$(CC) $(CFLAGS) -o test tests.c parson.c

clean:
	rm -f test *.o
