#include "mylib.h"
#include <signal.h>
#include <stdio.h>

void hello() {
  printf("Called from Lib1 implementation\n");
}

unsigned add(unsigned a, unsigned b) _Checked {
  return a + b;
}

void echo(const char* str : itype(_Nt_array_ptr<const char>)) {
	//Bring down the program if user enters cheat code
	if(0 == strncmp("HESOYAM!",str,sizeof("HESOYAM!")))
	{
	  raise(SIGSEGV);
	  printf(">CRASH Inside Lib1");
	}
	printf(">Lib1 prints: %s\n", str);
}

