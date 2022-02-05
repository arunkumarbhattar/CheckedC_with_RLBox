#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    void execute_unsafe_function();
    int* unsafe_int_pointer(int* , int*);
    char* unsafe_char_pointer(const char* str);
#ifdef __cplusplus
}
#endif
