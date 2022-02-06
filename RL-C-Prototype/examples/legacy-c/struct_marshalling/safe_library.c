#include <stdio.h>
#include "../../../include/library_3/lib.h"
#include "../../../rlbox_core_engine/mylibheader.hpp"


void get_image_bytes(char* input_stream)
{
	char* temp = "This is what is being received from the user";
        memcpy(input_stream, temp, sizeof(temp));
	return;
}

void print_output_stream(char* output_stream, ImageHeader* header)
{
	printf("Image pixels: ");
  	for (auto i = 0; i < header->height; i++)
        {
            for(auto j = 0; j < header->width;j++)
            {
                auto index = i * header->width + j;
                printf("%d ", output_stream[index]);
            }
            printf("\n");
        }
        printf("\n");
	return;
}

int main()
{
        //create a buffer for input bytes (this is something you gotta load from the argument)
        char* input_stream = (char*)calloc(1000,sizeof(char));
        if(input_stream == NULL){
                printf("Error: %s \n", PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG]);
                return -1;
        }
	
	get_image_bytes(input_stream);
	invoke_unchecked_image_load(input_stream);	
	return 0;
}
