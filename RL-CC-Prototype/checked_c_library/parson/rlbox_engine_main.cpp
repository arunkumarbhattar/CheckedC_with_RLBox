#include "rlbox_basic_headers.hpp"
#include "parson.h"
#include "lib_struct_file.h"
#include <cstring>

using namespace rlbox;
using namespace std;

using rlbox_sandbox_type = rlbox::rlbox_noop_sandbox;
using rlbox_sandbox_lib = rlbox::rlbox_sandbox<rlbox_sandbox_type>;
template<typename T>
using tainted_img = tainted<T, rlbox_sandbox_type>;

rlbox_load_structs_from_library(parson);

//we need to have a global static sandbox created
extern rlbox::rlbox_sandbox<rlbox_sandbox_type>* sandbox_chk_2_unchk = new rlbox_sandbox_lib();

/* Types and enums */
typedef struct json_object_t JSON_Object;
typedef struct json_array_t  JSON_Array;
typedef struct json_value_t  JSON_Value;

extern "C" void CreateSandbox()
{
         sandbox_chk_2_unchk->create_sandbox();
	 return;
}

void DeleteSandbox (rlbox_sandbox_lib *sandbox) {
         sandbox->destroy_sandbox();
         delete sandbox;
}

extern "C" JSON_Value * sandboxed_json_parse_file(const char *filename)
{
	auto tainted_file_name = sandbox_chk_2_unchk->malloc_in_sandbox<char>(strlen(filename));
	std::strncpy(tainted_file_name.unverified_safe_pointer_because(strlen(filename), "writing to region"), filename, strlen(filename));
	auto tainted_json_value = sandbox_chk_2_unchk->invoke_sandbox_function(json_parse_file, tainted_file_name);
 	//unmarshalling is not required here because after verification, this particular sandbox memory (in stack) gets untainted and can be directly de-reference to 
	//any static memory and passed out of this function scope	
	static JSON_Value return_val = (tainted_json_value->unverified_safe_because("Any value is safe for allocation for now"));
	return &return_val;
}

extern "C" JSON_Array * sandboxed_json_value_get_array  (const JSON_Value *value)
{
	//this has to be in a loop, because the structures are linked to each other like linked lists
	tainted<json_value_t* , rlbox_noop_sandbox> tainted_value = sandbox_chk_2_unchk->malloc_in_sandbox<json_value_t>(sizeof(*value));
	//tainted<json_value_t* , rlbox_noop_sandbox> tainted_value = value;
	while(value->parent != NULL)
	{
		tainted_value->parent = (tainted<json_value_t *, rlbox::rlbox_noop_sandbox>)sandbox_chk_2_unchk->malloc_in_sandbox<json_value_t>(sizeof(json_value_t));
		memcpy(tainted_value->parent.unverified_safe_pointer_because(sizeof(value->parent), "writing to region"), value->parent, sizeof(*(value->parent)));
		//We need to keep traversing in a linked list
		//tainted_value->parent = tainted_value->parent->parent;
		//value->parent = value->parent->parent;
	}
	tainted_value->type = value->type;
	tainted_value->value.unverified_safe_because("writing to region") = value->value;

	auto tainted_json_value = sandbox_chk_2_unchk->invoke_sandbox_function(json_value_get_array, tainted_value);
	static JSON_Array *return_val = (JSON_Array *)malloc(sizeof(JSON_Array));
		//the below always returns a non-pointer
		*return_val = (tainted_json_value->unverified_safe_because("Any value is safe for allocation for now"));
        return return_val;
}
