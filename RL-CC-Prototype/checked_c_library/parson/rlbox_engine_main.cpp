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
	
	//now here is the function to perform the marshalling from tainted to untainted
	
	static JSON_Value return_val = (tainted_json_value->unverified_safe_because("Any value is safe for allocation for now"));
	return &return_val;
}
