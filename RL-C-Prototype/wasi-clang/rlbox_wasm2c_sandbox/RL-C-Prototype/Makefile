.PHONY: hello clean
INC =-I include/rlbox/code/include

hello: rlbox_engine_main.cpp ./include/library_1/mylib.c ./include/library_1/mylib.h ./include/library_2/bn.c ./include/library_2/bn.h
	clang -g -std=c++17 $(CFLAGS) -c -Wall $(INC) rlbox_engine_main.cpp
	clang -g $(CFLAGS) -c -Wall ./include/library_1/mylib.c
	clang -g $(CFLAGS) -c -Wall ./include/library_2/bn.c
	clang++ -g $(CFLAGS) -Wall main.o mylib.o bn.o -o $@ -ldl

clean:
	-rm hello
