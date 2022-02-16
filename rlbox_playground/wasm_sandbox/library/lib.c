//Small library that simulates a typical image decoding library like libjpeg

#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include <inttypes.h>

// Parse just the header from the input bytes
ImageHeader* parse_image_header(char* in, char* host_memory_leak) {
   printf("Pre library crash Prints \n");
   // Return data to simulate parsing of a header
   //Simulate Segmentation fault in Sandbox -->
   /*
    *
    * Uncomment this code to simulate segmentation fault
    * Although, even if you uncomment, your system wont crash
    */
    //const char *s = NULL;
    //printf( "%c\n", s[0] );
    //printf("Post Crash Prints \n");

    ImageHeader* header = (ImageHeader*) malloc(sizeof(ImageHeader));
    header->status_code = 0;
    header->width = 10;
    header->height = 1;

    //this code snippet is to simulate an attempt to access/manipulate host(trusted) memory that was, assume, accidentally leaked.
    /*
    uintptr_t address;
    sscanf(host_memory_leak, "%" SCNuPTR, &address);
    //typecast the address to an int*
    int *p = (int*) address;
    //now modify the address pointer by dereferencing
    *p = 200;
    printf("p = %d \n", *p);
    */
    
    return header;
}

void parse_image_body(char* in, ImageHeader* header, OnProgress* on_progress, char* out) {
    // Simulate progress of parsing of image body
    for (unsigned int i = 1; i <= 100; i++) {
        on_progress(i);
    }

    // Simulate a write
    memset(out, 2, header->width * header->height);
}
