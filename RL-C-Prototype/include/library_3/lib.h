#pragma once 

#ifdef __cplusplus
extern "C" { 
#endif 

//Small library that simulates a typical image decoding library like libjpeg 

//Structure for the image header 
typedef struct {
	//Status of header parsing 
	//STATUS_SUCCEED on Success
	//failure code otherwise 
	unsigned int status_code;
	//Dimensions of the image
	unsigned int width;
	unsigned int height;
}ImageHeader;

//Status code used in header parsing 
#define HEADER_PARSING_STATUS_SUCCEEDED 0 
#define HEADER_PARSING_STATUS_INVALID 1
#define HEADER_PARSING_STATUS_INCOMPLETE 2 

//Callback to indicate progress 
typedef void (OnProgress)(unsigned int);

//parse the image header and return the header struct 
ImageHeader* parse_image_header(char* in);

//Parse image body into the output buffer out 
//OnProgress is a callback that is invoked with an intefer from 1 to 100 indicating progress
void parse_image_body(char*in, ImageHeader* header, OnProgress* on_progress, char* out);

#ifdef __cplusplus
}

#endif
