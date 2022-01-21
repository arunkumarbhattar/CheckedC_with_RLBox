.PHONY: hello clean
HEADER = ./include/
INC =-I/home/arunman_rb32/rlbox/rlbox_sandboxing_api/code/include/

hello: main.cpp ./include/lib1/mylib.c ./include/lib1/mylib.h ./include/lib2_tiny_bignum/bn.c ./include/lib2_tiny_bignum/bn.h
	clang -std=c++17 $(CFLAGS) -c -Wall  $(INC) main.cpp
	clang $(CFLAGS) -c -Wall ./include/lib1/mylib.c
	clang $(CFLAGS) -c -Wall ./include/lib2_tiny_bignum/bn.c
	clang++ $(CFLAGS) -Wall main.o mylib.o bn.o -o $@

clean:
	-rm hello
