#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <functional>
//include the c++ header file that provides
//interface for all libraries
#include "mylibheader.hpp"
#include <rlbox.hpp>
#include <rlbox_noop_sandbox.hpp>

using namespace rlbox;
using namespace std;

extern "C" int invoked_unchecked_function(char* func_name, int* a, int*b, int* result)
{
	if(execute_unchecked_function(func_name, a, b, result))
		return 1;
	else
		return 0;
}

bool execute_unchecked_function(char* func_name, int* a, int* b, int* result)
{
	/*
	 * In the future the sandbox object will be created at the beginning
	 * and will be accessible globall across this c++ glue code
	 */
        rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
	sandbox.create_sandbox();
	/*In the future, as we have a large number of C Unchecked libraries,
	 We can have a std::multimap<string func_name, string library_name.so> to 
	 return us the exact library we wish to open for this function call
	*/
	cout << "Opening Shared library\n";
	void* handle = dlopen("./include/library_2/bn.so", RTLD_LAZY);
	if (!handle) {
             cerr << "Cannot open library: " << dlerror() << '\n';
             return false;
    	}
	
	// Reset errors
        dlerror();

	// load the symbol
   	cout << "Loading symbol...\n";
    	typedef void (*unchecked_func_t)(int);
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

	 auto t_a = sandbox.malloc_in_sandbox<int>(1);
	 auto t_b = sandbox.malloc_in_sandbox<int>(1);
	 auto t_result = sandbox.malloc_in_sandbox<int>(1);
	 rlbox::memcpy(sandbox, t_a, a, 1);
	 rlbox::memcpy(sandbox, t_b, b, 1);
	 auto tainted_result = sandbox.malloc_in_sandbox<int>(1);
	 cout << "Calling Unchecked function thorugh Sandbox...\n";
	//sandbox.invoke_sandbox_function(printf, t_a, t_b,
	//	t_result);
	// The decltype thing is messy!
	sandbox.invoke_sandbox_function_ptr(exit, unchecked_func, 1);
	 auto result_t = tainted_result.copy_and_verify([](std::unique_ptr<int > val){
	 	if(*val.get() <100)
		{
		   cout << "Within legal return range from the unchecked RLBoxed function...\n";		
		   return std::move(val);
	 	}
	 });

	 //untaint the return result and assign it to result (untainted) memory
	 result = result_t.get();
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
