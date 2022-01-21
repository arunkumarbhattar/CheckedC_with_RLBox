#include "mylib.h"

#include <stdio.h>

void hello() {
  printf("Hello world from mylib\n");
}

unsigned add(unsigned a, unsigned b) _Checked {
  return a + b;
}

void echo(const char* str : itype(_Nt_array_ptr<const char>)) {
  printf("> mylib: %s\n", str);
}

int main()
{
	printf("hello\n");
	return 0;
}
