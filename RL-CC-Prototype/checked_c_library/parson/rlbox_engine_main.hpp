#include <stdint.h>
#include "parson.h"
#pragma once

/* Types and enums */
typedef struct json_object_t JSON_Object;
typedef struct json_array_t  JSON_Array;
typedef struct json_value_t  JSON_Value;

#ifdef __cplusplus
extern "C" {
#endif
   /* This is the interface for Checked-C library to access the unchecked library code */
	JSON_Value* sandboxed_json_parse_file(const char *filename);
	void CreateSandbox();
#ifdef __cplusplus
}
#endif

