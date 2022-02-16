//Small library that simulates a typical decoding library like libpeg 

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "lib.h"

//Parse just the header from the input bytes 

ImageHeader* parse_image_header(char* in) {
	//Return data to simulate parsing of a header 
	ImageHeader* header = (ImageHeader*)malloc(sizeof(ImageHeader));
	header->status_code = 0;
	header->width = 10;
	header->height = 10;
	return header;
}

void parse_image_body(char* in, ImageHeader* header, OnProgress* on_progress, char* out)
{
	//Simulate progress of parsing of image body 
	for(unsigned int i = 1; i<100;i++)
		on_progress(i);

	//Simulate a write 
	memset(out, 2, header->width * header->height);
}

//unsigned int progress must be checked before being parsed into this
//below function must be invoked via the sandbox
void image_parsing_progress(unsigned int progress){
        printf("Image parsing: %d out of 100\n", progress);
	return;
}

int validate_image_headers(ImageHeader* header)
{
	printf("Program message code: %d\n", header->status_code);
        if(header->status_code != HEADER_PARSING_STATUS_SUCCEEDED)
	{
		printf("Memory should not be allocated as Program message code: %d\n", header->status_code);
		return 0; 
	}
	return ((header->height) * (header->width));	
}

