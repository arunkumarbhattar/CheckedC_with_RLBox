#include "mylib.h"

#include <stdio.h>

void hello() {
  printf("Called from Lib1 implementation\n");
}

unsigned add(unsigned a, unsigned b) _Checked {
  return a + b;
}

void echo(const char* str : itype(_Nt_array_ptr<const char>)) {
      	printf(">Lib1 prints: %s\n", str);
}

