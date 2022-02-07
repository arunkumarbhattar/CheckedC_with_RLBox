#include <stdio.h>
#include "unsafe_library.h"
#include "../../../rlbox_core_engine/mylibheader.hpp"
int main()
{
        int a =100;
        int b = 20;
	int *result;
	result = (int*)malloc(1*sizeof(int));
	char* str_test = "InputStringToUnsafeFunction";
	//call unsafe function two 
        invoked_unchecked_function("unsafe_int_pointer", &a, &b, result);
        printf("Result is %d \n", *result);
	//invoke unsafe function three
	char* string_pointer_to_be_written_to = calloc(40,sizeof(char));
	invoke_unchecked_print_function("unsafe_char_pointer", string_pointer_to_be_written_to);
        printf("string_pointer_to_be_written_to: %s ",string_pointer_to_be_written_to);

	return 0;
}
