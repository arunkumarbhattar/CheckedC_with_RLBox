#include "rlbox_basic_headers.hpp"
//C++ compiler does not recognize/understand CheckedC, hence for calls to libraries we are including .h files that have not been converted to Checked-C 
#include "../include/library_3/lib.h"
#include "../include/library_3/lib_struct_file.h"
#include "../include/library_3/tainted_sub_functions.hpp"
//Again here, irrespective if your host code(safe_library.h here) is checkedC or not, we point to NON-CheckedC .h library
#include "../../rlbox_playground/struct_marshalling/safe_library.h"

// Configure RLBox
#define RLBOX_SINGLE_THREADED_INVOCATIONS

#ifdef USE_WASM
    // Configure RLBox for wasm sandbox
    #include "../include/library_3/wasm_c_definitions/lib_wasm.h"
    #include <rlbox_wasm2c_sandbox.hpp>    
    #define RLBOX_USE_STATIC_CALLS() rlbox_wasm2c_sandbox_lookup_symbol
    using sandbox_type_type = rlbox::rlbox_wasm2c_sandbox;
#else
    // Configure RLBox for noop sandbox
    #define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
    using sandbox_type_type = rlbox::rlbox_noop_sandbox;
#endif

using namespace rlbox;
using namespace std;

using rlbox_sandbox_lib = rlbox::rlbox_sandbox<sandbox_type_type>;
template<typename T>
using tainted_img = tainted<T, sandbox_type_type>;

rlbox_load_structs_from_library(lib);

//we need to have a global static sandbox created
extern rlbox::rlbox_sandbox<sandbox_type_type>* sandbox_chk_2_unchk = new rlbox_sandbox_lib();

extern "C" void CreateSandbox()
{
         sandbox_chk_2_unchk->create_sandbox();
	 return;
}

extern "C" void DeleteSandbox () {
     sandbox_chk_2_unchk->destroy_sandbox();
     delete sandbox_chk_2_unchk;
     return;
}

//ImageHeader* temp_parse_image_header(char*);
extern "C" int invoke_unchecked_image_load(char* input_stream)
{
	//auto sandbox_chk_2_unchk = CreateSandbox();
	
	auto tainted_input_stream = sandbox_chk_2_unchk->malloc_in_sandbox<char>(strlen(input_stream));
	if (!input_stream) {
        	cerr << "Error: " << PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] << "\n";
        	return 1;
    	}

	auto header = sandbox_chk_2_unchk->invoke_sandbox_function(parse_image_header, tainted_input_stream);
	
	//tainted_status_code is safe, hence it can be passed to the unsafe library 
 	auto tainted_output_stream_size = sandbox_chk_2_unchk->invoke_sandbox_function(validate_image_headers, header);	
	auto output_size = tainted_output_stream_size.unverified_safe_because("Any value is safe for allocation for now");
	auto tainted_output_stream = sandbox_chk_2_unchk->malloc_in_sandbox<char>(output_size);
	if(!tainted_output_stream)
	{
		cerr<<"Error: "<< PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] <<"\n";
		return 1;
	}

	/*
	 * We cannot directly register a C function in sandbox, we need to only pass a function pointer that actually takes
	 * in and returns tainted types
	 *
	 * 
	Convert the normal function pointer to a tainted function pointer 
	we need to pass a callback to parse_image_body, so we register it here
    	auto cb_image_parsing_progress = sandbox_chk_2_unchk->register_callback(image_parsing_progress);
	*/
	auto cb_image_parsing_progress = sandbox_chk_2_unchk->register_callback(sandboxed_image_parsing_progress);
	/*
	 *We cannot directly pass a untainted function pointer, we are only allowed to pass a tainted function pointer
	 * Hence if our function ever accepts a function pointer, we have to manually create a tainted function pointer, 
	 * and then register it, and then parse the registered callback as an argument
	 *
	 *
	invoke via sandbox_invoke and pass in tainted versions of the parameters 
	*/
	sandbox_chk_2_unchk->invoke_sandbox_function(parse_image_body, tainted_input_stream, header, cb_image_parsing_progress, tainted_output_stream);
	//unfortunately due to the limitation of the wasi-clang compiler, you cannot make calls to the checked code
	//sandbox_chk_2_unchk->invoke_sandbox_function(print_output_stream, tainted_output_stream, header);
	print_output_stream(tainted_output_stream.unverified_safe_pointer_because(100,"Any value is safe for allocation for now"), header.unverified_safe_pointer_because(100, "Any value is safe for allocation for now"));

	//done.. clean up
	sandbox_chk_2_unchk->free_in_sandbox(header);
	delete[] input_stream;
	sandbox_chk_2_unchk->free_in_sandbox(tainted_input_stream);
	sandbox_chk_2_unchk->free_in_sandbox(tainted_output_stream);
	return 0;
}

