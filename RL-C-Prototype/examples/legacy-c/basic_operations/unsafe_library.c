#include <stdio.h>
#include <stdlib.h>

void execute_unsafe_function() {
  printf("Call executed from unsafe library\n");
  return;
}

/*this is an example of a unsafe (unchecked) block that returns an int pointer
  the verifier for the return int pointer should ideally be written as part of the 
  untainting process in the rlbox (c++) file. 
  I believe every unsafe library file (containing a bunch of unsafe functions) should 
  have their own c++ (rlboxed) file. This file should hold the interface of these unsafe
  functions to safe functions. 
  The verifiers required for untaining too will be written in these c++ files.
 */
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

