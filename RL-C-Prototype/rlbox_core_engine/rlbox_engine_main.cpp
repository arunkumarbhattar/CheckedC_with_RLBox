#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol
#include <dlfcn.h>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <iostream>
#include <functional>
#include <assert.h>
//include the c++ header file that provides
//interface for all libraries
#include "mylibheader.hpp"
#include <rlbox.hpp>
#include <rlbox_noop_sandbox.hpp>
//gotta include the library header that has the struct definiton
#include "../include/library_3/lib.h"
#include "../include/library_3/lib_struct_file.h"

#include "../examples/legacy-c/struct_marshalling/safe_library.h"

using namespace rlbox;
using namespace std;

using rlbox_sandbox_type = rlbox::rlbox_noop_sandbox;
using rlbox_sandbox_lib = rlbox::rlbox_sandbox<rlbox_sandbox_type>;
template<typename T>
using tainted_img = tainted<T, rlbox_sandbox_type>;

rlbox_load_structs_from_library(lib);

rlbox_sandbox_lib* CreateSandbox()
{
         rlbox_sandbox_lib* sandbox = new rlbox_sandbox_lib();
         sandbox->create_sandbox();
         return sandbox;
}

void DeleteSandbox (rlbox_sandbox_lib *sandbox) {
         sandbox->destroy_sandbox();
         delete sandbox;
}

//ImageHeader* temp_parse_image_header(char*);
extern "C" int invoke_unchecked_image_load(char* input_stream)
{
	auto sandbox_imaging = CreateSandbox();
	
	auto tainted_input_stream = sandbox_imaging->malloc_in_sandbox<char>(sizeof(input_stream));
	if (!input_stream) {
        	cerr << "Error: " << PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] << "\n";
        	return 1;
    	}

	auto header = sandbox_imaging->invoke_sandbox_function_char_ptr(parse_image_header, parse_image_header, tainted_input_stream);
	/*
	 * I dont know if the below will work or not, I think we need manual unmarshalling
	 *
	 */
	tainted_img<unsigned int> tainted_status_code = header->status_code;
	auto verified_status_code = tainted_status_code.copy_and_verify([](unsigned int value){
            // since status code is being used to index an array below, we need
            // to make sure that the value is less than that array's size
            auto program_status_length = sizeof(PROGRAM_STATUS_MSG)/sizeof(PROGRAM_STATUS_MSG[0]);
            //just abort if the value is out of bounds
            assert(value < program_status_length);
            //if safe, return the value 
            return value;
            });
	
	//tainted_status_code is safe, hence it can be passed to the unsafe library 
 	auto tainted_output_stream_size = sandbox_imaging->invoke_sandbox_function(validate_image_headers, tainted_status_code);	

	auto output_size = tainted_output_stream_size.unverified_safe_because("Any value is safe for allocation for now");
	auto tainted_output_stream = sandbox_imaging->malloc_in_sandbox<char>(output_size);
	if(!tainted_output_stream)
	{
		cerr<<"Error: "<< PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] <<"\n";
		return 1;
	}

	//invoke via sandbox_invoke and pass in tainted versions of the parameters 
	sandbox_imaging->invoke_sandbox_function(parse_image_body, tainted_input_stream, header, image_parsing_progress, tainted_output_stream);
	sandbox_imaging->invoke_sandbox_function(print_output_stream, tainted_output_stream, header);
	
	//done.. clean up
	sandbox_imaging->free_in_sandbox(header);
	delete[] input_stream;
	sandbox_imaging->free_in_sandbox(tainted_input_stream);
	sandbox_imaging->free_in_sandbox(tainted_output_stream);
	DeleteSandbox(sandbox_imaging);
	return 0;
}

extern "C" int invoked_unchecked_function(char* func_name, int* a, int*b, int* result)
{
	if(execute_unchecked_function(func_name, a, b, result))
		return 1;
	else
		return 0;
}

char* test(char*);
int invoke_unchecked_print_function(char* func_name, char* string, char* output)
{
	auto sandbox_chk_2_unchk = CreateSandbox();
	/*In the future, as we have a large number of C Unchecked libraries,
         We can have a std::multimap<string func_name, string library_name.so> to
         return us the exact library we wish to open for this function call
        */
        cout << "Opening Shared library\n";
        void* handle = dlopen("unsafe_lib.so", RTLD_LAZY);
        if (!handle) {
             cerr << "Cannot open library: " << dlerror() << '\n';
             return false;
        }

	// Reset errors
        dlerror();

        // load the symbol
        cout << "Loading symbol...\n";
        typedef char (*unchecked_func_t)(char* );
        //define in the shared library that was opened
        std::string unchecked_func_str(func_name);
        //std::string unchecked_func(func_name);
        unchecked_func_t unchecked_func = (unchecked_func_t) dlsym(handle, unchecked_func_str.c_str());

        const char *dlsym_error = dlerror();
        if (dlsym_error) {
            cerr << "Cannot load symbol: " << dlsym_error <<
            '\n';
            dlclose(handle);
            return false;
        }

        //create tainted types for use in RL-Box{Unchecked} region
        /* In the future, for variable arguments, we will use <cstdarg>.
         * Therefore a function call with (a1,a2,...an-1,an) would be
         * interpreted with arguments as (a1...an-1) and return value an
         * The sandboxed used below must be a global sandbox across this c++ program
         * "typeof" will be used find and insert the type (T) of varargs
         * into the malloc_in_sandbox<T>
         */
	 
	 const char* temp_string = "Pass this string into unsafe territory";
	 size_t temp_str_size = strlen(temp_string) + 1;
	 auto taintedStr = sandbox_chk_2_unchk->malloc_in_sandbox<char>(temp_str_size);
	 std::strncpy(taintedStr.unverified_safe_pointer_because(temp_str_size,"writing to region"), temp_string, temp_str_size);
	 auto tainted_result = sandbox_chk_2_unchk->malloc_in_sandbox<char>(100*sizeof(char));
	 tainted_result = sandbox_chk_2_unchk->invoke_sandbox_function_char_ptr(test, unchecked_func, taintedStr);
	 auto result_t = tainted_result.copy_and_verify_string([](std::unique_ptr<char[]> val){
             if(val.get() == "#($%&(%_$@(")
             {
                cerr << "Illegal memory pointing char* returned \n";
		return std::move(val);
	     }
	     else 
	     	return std::move(val);
         });
         
         //untaint the return result and assign it to result (untainted) memory
         strncpy(output, result_t.get(), strlen(result_t.get()));
	 DeleteSandbox(sandbox_chk_2_unchk);
	 return true;
}
int* tempptr(int*, int*);

bool execute_unchecked_function(char* func_name, int* a, int* b, int* result)
{
	auto sandbox_chk_2_unchk = CreateSandbox();

	/*In the future, as we have a large number of C Unchecked libraries,
	 We can have a std::multimap<string func_name, string library_name.so> to 
	 return us the exact library we wish to open for this function call
	*/
	cout << "Opening Shared library\n";
	void* handle = dlopen("unsafe_lib.so", RTLD_LAZY);
	if (!handle) {
             cerr << "Cannot open library: " << dlerror() << '\n';
             return false;
    	}
	
	// Reset errors
        dlerror();

	// load the symbol
   	cout << "Loading symbol...\n";
    	typedef int (*unchecked_func_t)(int*, int*);
	//define in the shared library that was opened
    	std::string unchecked_func_str(func_name);
	//std::string unchecked_func(func_name);
        unchecked_func_t unchecked_func = (unchecked_func_t) dlsym(handle, unchecked_func_str.c_str());
        
	const char *dlsym_error = dlerror();
    	if (dlsym_error) {
            cerr << "Cannot load symbol: " << dlsym_error <<
            '\n';
            dlclose(handle);
            return false;
    	}

	//create tainted types for use in RL-Box{Unchecked} region 
	/* In the future, for variable arguments, we will use <cstdarg>.
	 * Therefore a function call with (a1,a2,...an-1,an) would be 
	 * interpreted with arguments as (a1...an-1) and return value an
         * The sandboxed used below must be a global sandbox across this c++ program
	 * "typeof" will be used find and insert the type (T) of varargs 
	 * into the malloc_in_sandbox<T>	
       	 */

	 auto t_a = sandbox_chk_2_unchk->malloc_in_sandbox<int>(1);
	 auto t_b = sandbox_chk_2_unchk->malloc_in_sandbox<int>(1);
	 //auto t_result = sandbox_chk_2_unchk->malloc_in_sandbox<int>(1);
	 rlbox::memcpy(*sandbox_chk_2_unchk, t_a, a, 1);
	 rlbox::memcpy(*sandbox_chk_2_unchk, t_b, b, 1);
	 auto tainted_result = sandbox_chk_2_unchk->malloc_in_sandbox<int>(1);
	 cout << "Calling Unchecked function thorugh Sandbox...\n";
	 auto t_result = sandbox_chk_2_unchk->invoke_sandbox_function_ptr(tempptr, unchecked_func, t_a, t_b);
	 auto result_t = t_result.copy_and_verify([](std::unique_ptr<int > val){
	 	if(*val.get() <100)
		{
		   cout << "Within legal return range from the unchecked RLBoxed function...\n";		
		   return std::move(val);
	 	}
		else
		{
	           cout << "Illegal values returned from unsafe RLBoxed function...\n";
		   return std::move(std::unique_ptr<int>(new int(0)));
		}
	 });

	 //untaint the return result and assign it to result (untainted) memory
	 *result = *result_t.get();
	 DeleteSandbox(sandbox_chk_2_unchk);
	 return true;
}

//callback object is returned after registering the below callback with the sandbox.
//Then we invoke C's Unchecked function by passing both the Unchecked function and the 
//callback object (tainted function callback) as arguments to the "invoke_sandbox_function"
tainted<int, rlbox_noop_sandbox> hello_cb(rlbox_sandbox<rlbox_noop_sandbox>& _,
              tainted<const char*, rlbox_noop_sandbox> str) {

    //The below function "copy_and_verify_string" checks if the string argument of 
    //library function call_cb is safe or not. Lets assume it does so.  
    auto checked_string =
    str.copy_and_verify_string([](std::unique_ptr<char[] > val) 
    {
        printf("Length of the string is: %d, ", (int)strlen(val.get()));
  	return strlen(val.get()) < 1024 ? std::move(val) : nullptr;
    });
  printf(" and the string is: %s\n", checked_string.get());
  return 1;
}