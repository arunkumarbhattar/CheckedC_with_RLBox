#pragma once
//definition of structs go here (these definitions would later be auto generated and written to this file 

#define sandbox_fields_reflection_lib_class_ImageHeader(f,g, ...)\
        f(unsigned int, status_code, FIELD_NORMAL, ##__VA_ARGS__)g()   \
        f(unsigned int, width, FIELD_NORMAL, ##__VA_ARGS__)g()        \
        f(unsigned int, height, FIELD_NORMAL, ##__VA_ARGS__)g() 

#define sandbox_fields_reflection_lib_allClasses(f, ...)     \
        f(ImageHeader, lib, ##__VA_ARGS__)


