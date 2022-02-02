.PHONY: hello clean
INC =-I include/rlbox/code/include

hello: main.cpp ./include/lib1/mylib.c ./include/lib1/mylib.h ./include/lib2_tiny_bignum/bn.c ./include/lib2_tiny_bignum/bn.h
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) main.cpp
	clang -g $(CFLAGS) -c -Wall ./include/lib1/mylib.c
	clang -g $(CFLAGS) -c -Wall ./include/lib2_tiny_bignum/bn.c
	clang++ -g $(CFLAGS) -Wall main.o mylib.o bn.o -o $@ -ldl

clean:
	-rm hello
