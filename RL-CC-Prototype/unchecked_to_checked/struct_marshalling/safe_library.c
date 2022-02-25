#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../RL-C-Prototype/include/library_3/lib.h"
#include "../../../RL-C-Prototype/rlbox_core_engine/mylibheader.hpp"


void get_image_bytes(_Array_ptr<char> input_stream)
{
	_Nt_array_ptr<char> temp : byte_count(44) = "This is what is being received from the user";
        memcpy<char>(_Assume_bounds_cast<_Array_ptr<char>>(input_stream, byte_count(100)), _Assume_bounds_cast<_Nt_array_ptr<char>>(temp, count(44)), 44);
	return;
}

void print_output_stream(_Array_ptr<char> output_stream, _Ptr<ImageHeader> header)
_Checked {
	_Unchecked { printf("Image pixels: "); };
  	for (int i = 0; i < header->height; i++)
        {
            for(int  j = 0; j < header->width;j++)
            {
                int index = i * header->width + j;
		_Nt_array_ptr<char> opstream  = "0";
		_Unchecked {
		_Nt_array_ptr<char> arg1 = _Assume_bounds_cast<_Nt_array_ptr<char>>((output_stream+index), count(0));
			printf("%d ", *arg1); };
            }
            _Unchecked { printf("\n"); };
        }
        _Unchecked { printf("\n"); };
	return;
}

int main()
{
	//initialize the global sandbox
	CreateSandbox();
	//create a buffer for input bytes (this is something you gotta load from the argument)
        char* input_stream = (char*)calloc<char>(1000,sizeof(char));
        if(input_stream == NULL)_Checked {
                _Unchecked { printf("Error: %s \n", PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG]); };
                return -1;
        }
	
	get_image_bytes(_Assume_bounds_cast<_Array_ptr<char>>(input_stream, bounds(unknown)));
	invoke_unchecked_image_load(input_stream);	
	return 0;
}
