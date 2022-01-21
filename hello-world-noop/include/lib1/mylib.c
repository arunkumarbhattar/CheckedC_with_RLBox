#include "mylib.h"

#include <stdio.h>

void hello() {
  printf("High performance Guaranteed\n");
}

unsigned add(unsigned a, unsigned b) _Checked {
  return a + b + 99;
}

void echo(const char* str : itype(_Nt_array_ptr<const char>)) {
	//_Nt_array_ptr<const char> temp : bounds(str,str+100)= NULL;
        //temp= _Assume_bounds_cast<_Nt_array_ptr<const char>>(str, bounds(str,str+100));
      	printf("> mylib: %s\n", str);
}

