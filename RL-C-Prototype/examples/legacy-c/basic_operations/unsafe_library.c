#include <stdio.h>
#include <stdlib.h>

void execute_unsafe_function() {
  printf("Call executed from unsafe library\n");
  return;
}

int* unsafe_int_pointer(int* a, int* b) {
     int p = *a + *b;
     int *ret;
     ret  = (int*)malloc(1*sizeof(int));
     *ret = p;
     return ret;
}

char* unsafe_char_pointer(const char* str) {
	char* ret = "#($%&(%_$@(";
	return ret;
}

