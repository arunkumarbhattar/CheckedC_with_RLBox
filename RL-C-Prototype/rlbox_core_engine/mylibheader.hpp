#include <stdint.h>
#pragma once

#ifdef __cplusplus
extern "C" {
#endif
   /* The below are functions that Host Code (Safe/Checked) would use to handle calls to unchecked code THROUGH RLBOX 
    */
    int invoked_unchecked_function(char* func_name, int* a, int*b, int* result);
    int invoke_unchecked_print_function(char* func_name, char* output);
    void CreateSandbox();
    void DeleteSandbox ();

    unsigned add(unsigned, unsigned);
    void echo(const char* str);
    
    int call_cb(int (*cb) (const char* str));
    void _unsafe_add(int* a, int* b, int* sum);
#ifdef __cplusplus
}
bool execute_unchecked_function(char* func_name, int* a, int*b, int* result);
#endif
