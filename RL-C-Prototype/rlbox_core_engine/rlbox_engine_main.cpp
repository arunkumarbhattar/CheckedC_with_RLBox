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

using namespace rlbox;
using namespace std;

using rlbox_sandbox_type = rlbox::rlbox_noop_sandbox;
using rlbox_sandbox_lib = rlbox::rlbox_sandbox<rlbox_sandbox_type>;
template<typename T>
using tainted_img = tainted<T, rlbox_sandbox_type>;

//definition of structs go here (these definitions would later be auto generated and stored in the library directory 
//in a seperate library.h file 
#define sandbox_fields_reflection_exampleapp_class_ImageHeader(f,g, ...)\
	f(unsigned int, status_code, FIELD_NORMAL, ##__VA_ARGS__)g()   \
	f(unsigned int, width, FIELD_NORMAL, ##__VA_ARGS__)g()	      \
        f(unsigned int, height, FIELD_NORMAL, ##__VA_ARGS__)g() 

#define sandbox_fields_reflection_exampleapp_allClasses(f, ...)     \
	f(ImageHeader, exampleapp, ##__VA_ARGS__)

rlbox_load_structs_from_library(exampleapp);

static const char* PROGRAM_STATUS_MSG[] = {
	"Succeeded",
	"Invalid image",
	"Incomplete Image",
	"Memory allocation failure"
};

#define MEMORY_ALLOC_ERR_MSG 3

void image_parsing_progress(rlbox_sandbox<rlbox_sandbox_type>& sandbox, tainted_img<unsigned int> progress){
	auto checked_progress = progress.copy_and_verify([](unsigned int value){
		//progress is expected to be between 1 and 100, so we check this 
		//If we dont check for this condition, and the library returned an out of range value 
		//like 1000, there wouldnt be any safety issue, but the application would just print a super 
		//confusing and awkward message, something like "Image parsing: 1000 out of 100".
		assert(value >=1 && value <=100);
		return value;});
	std::cout <<"Image parsing: "<<checked_progress<<" out of 100\n";
}

void get_image_bytes(char* input_stream)
{
	//dummy function 
}

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

extern "C" int invoke_unchecked_image_load()
{
	auto sandbox_imaging = CreateSandbox();
	
	//create a buffer for input bytes (this is something you gotta load from the argument)
	char* input_stream = new char[100];
	if(!input_stream){
		cerr << "Error: "<<PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] <<"\n";
		return 1;
	}

	//Read bytes from an image file into input_stream (yeah, this must be loaded from the argument)
	get_image_bytes(input_stream);

	//Create a buffer that will hold the input bytes inside the sandbox
	auto tainted_input_stream = sandbox_imaging->malloc_in_sandbox<char>(100);
	if (!input_stream) {
        cerr << "Error: " << PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] << "\n";
        return 1;
    	}

	//Copy the input bytes into the buffer inside the sandbox 
	rlbox::memcpy(*sandbox_imaging, tainted_input_stream, input_stream, 100u);

	//Parse header of the image to get its dimensions 
	//invoke the function inside the sandbox 
	//We pass in the tainted_input_stream instead of input_stream 
	//This is because the sandbox cannot acces input_stream since it is in 
	//the application's memory 
	auto header = sandbox_imaging->sandbox_invoke( parse_image_header, tainted_input_stream);
	
        //we make a copy of the tainted status_code in a local variable 
	//this is a good practice , since we are reating it twice below 
	//Making a copy will precent TOCTOU style attacks 
	tainted_img<unsigned int> tainted_status_code = header->status_code;

	/*Below we check an error code and early exit 
	Note the result of checking of a tainted value is itself tainted 
	But in this case we can remove the taining since the worst thing 
	that can happen is that we just safely exit the program.
	We use unverified_safe_because to remove tainting. It takes a string as 
	a parameter which is basically just a comment (the string is ignored, but 
	required for documentation) */	

	if ((tainted_status_code != HEADER_PARSING_STATUS_SUCCEEDED)
	    .unverified_safe_because("Worst case we will exit early"))
	{
	    //we index an array with tainted_status_code so it needs to be verified, else we cannot use it 
	    auto verified_status_code = tainted_status_code.copy_and_verify([](unsigned int value){
	    // since status code is being used to index an array below, we need
            // to make sure that the value is less than that array's size
            auto program_status_length = sizeof(PROGRAM_STATUS_MSG)/sizeof(PROGRAM_STATUS_MSG[0]);
	    //just abort if the value is out of bounds
	    assert(value < program_status_length);
	    //if safe, return the value 
	    return value;
	    });

	    cerr<<"Error: "<<PROGRAM_STATUS_MSG[verified_status_code] <<"\n";
	    return 0;
	}

	//Again width and height are used multiple times in the below code, so lets copy it a local variable first 
	tainted_img<unsigned int> tainted_height = header->height;
	tainted_img<unsigned int> tainted_width = header->width;

	//we need to allocate output_stream inside the sandbox so that it is accessible to the sandbox 
	//let us also rename it to tainted_output_stream
	//we need to untaint the expression tainted_height * tainted_width
	//Since this is being used only for an allocation pretty much any value is safe 
	//In fact, this is fine even if the multiply results in an integer overflow
	//Alternatively, if our application assumes there is a maximum size of the image, we should check this value here. 
	auto output_size = (tainted_height * tainted_width).unverified_safe_because("Any value is safe for allocation");
	auto tainted_output_stream = sandbox_imaging->malloc_in_sandbox<char>(output_size);
	if(!tainted_output_stream)
	{
		cerr<<"Error: "<< PROGRAM_STATUS_MSG[MEMORY_ALLOC_ERR_MSG] <<"\n";
		return 1;
	}

	//we need to pass a callback to parse_image_body, so we register it here 
	auto cb_image_parsing_progress = sandbox_imaging->register_callback(image_parsing_progress);
	
	//invoke via sandbox_invoke and pass in tainted versions of the parameters 
	sandbox_imaging->invoke_sandbox_function(parse_image_body, tainted_input_stream, header, cb_image_parsing_progres, tainted_output_stream);

	cout << "Image pixels: " << endl;
	//Loop now iterates over the tainted height and width of the image 
	//This the loop exit condition "i<tainted_height" and "j<tainted_width"
	//return tainted_values. We need to untaint them.
	//Untainting these variables gives the library influence over how many loop iterations are executed.
	//On inspection, we can see that this loop is safe no matter how many iteratiosn are run.
	//So we can remove the tainting.
	for (auto i = 0; i<tainted_height.unverified_safe_because("safe for any value");i++)
	{
	    for(auto j = 0; j< tainted_width.unverified_safe_because("safe for any value");j++)
	    {
		auto index = i*tainted_width +j;
		//note the expression "tainted_output_stream[index]" indexes an 
		//array with a tainted value jere. But the array itself is tainted. When indexing 
		//tainted arrays, rlbox inserts a dynamic check to ensure the memory access is restricted to the sandbox.
		cout<<(unsigned int) tainted_output_stream[index].unverified_safe_because("pixel value can be anything") <<" ";
            }
	    std::cout<<std::endl;
	}
	std::cout <<std::endl;
	
	sandbox_imaging->free_in_sandbox(header);
	delete[] input_stream;
	sandbox_imaging->free_in_sandbox(tainted_input_stream);
	sandbox_imaging->free_in_sandbox(tainted_output_stream);
	cb_image_parsing_progress.unregister();
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
