#pragma once 

#ifdef __cplusplus
extern "C" {
#endif

void get_image_bytes(char* input_stream);
void print_output_stream(char* output_stream, ImageHeader* header);

#ifdef __cplusplus
}
#endif
