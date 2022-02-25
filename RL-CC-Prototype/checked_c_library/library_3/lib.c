//Small library that simulates a typical decoding library like libpeg 

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "lib.h"

//Parse just the header from the input bytes 

_Ptr<ImageHeader> parse_image_header(_Ptr<char> in) {
	//Return data to simulate parsing of a header 
	_Ptr<ImageHeader> header = (_Ptr<ImageHeader>)malloc<ImageHeader>(sizeof(ImageHeader));
	header->status_code = 0;
	header->width = 10;
	header->height = 10;
	return header;
}

void parse_image_body(_Ptr<char> in, _Ptr<ImageHeader> header, _Ptr<void (unsigned int)> on_progress, _Array_ptr<char> out)
{
	//Simulate progress of parsing of image body 
	for(unsigned int i = 1; i<100;i++)
		on_progress(i);

	//Simulate a write 
	memset(_Assume_bounds_cast<_Ptr<char>>(out), 2, header->width * header->height);
}

//unsigned int progress must be checked before being parsed into this
//below function must be invoked via the sandbox
void image_parsing_progress(unsigned int progress)_Checked {
        _Unchecked { printf("Image parsing: %d out of 100\n", progress); };
	return;
}

int validate_image_headers(_Ptr<ImageHeader> header)
_Checked {
	_Unchecked { printf("Program message code: %d\n", header->status_code); };
        if(header->status_code != HEADER_PARSING_STATUS_SUCCEEDED)
	{
		_Unchecked { printf("Memory should not be allocated as Program message code: %d\n", header->status_code); };
		return 0; 
	}
	return ((header->height) * (header->width));	
}

