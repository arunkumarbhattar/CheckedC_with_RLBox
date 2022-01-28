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
#include "../rlbox_sandboxing_api/code/include/rlbox.hpp"
#include "../rlbox_sandboxing_api/code/include/rlbox_noop_sandbox.hpp"
//C-Library for dlopen 
using namespace rlbox;
using namespace std;

extern "C" int invoked_unchecked_function(char* func_name, int* a, int*b, int* result)
{
	/*
	 * In the future the sandbox object will be created at the beginning
	 * and will be accessible globall across this c++ glue code
	 */
        rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
	/*In the future, as we have a large number of C Unchecked libraries,
	 We can have a std::multimap<string func_name, string library_name.so> to 
	 return us the exact library we wish to open for this function call
	*/
	cout << "Opening Shared library\n";
	void* handle = dlopen("./bn.so", RTLD_LAZY);
	if (!handle) {
             cerr << "Cannot open library: " << dlerror() << '\n';
             return 1;
    	}

	// load the symbol
   	cout << "Loading symbol...\n";
    	typedef void (*unchecked_func_t)();
	//define in the shared library that was opened
    	std::string unchecked_func_str(func_name);
	//std::string unchecked_func(func_name);
        unchecked_func_t unchecked_func = (unchecked_func_t) dlsym(handle, unchecked_func_str.c_str());
        
	const char *dlsym_error = dlerror();
    	if (dlsym_error) {
            cerr << "Cannot load symbol: " << dlsym_error <<
            '\n';
            dlclose(handle);
            return 1;
    	}

	//create tainted types for use in RL-Box{Unchecked} region 
	/* In the future, for variable arguments, we will use <cstdarg>.
	 * Therefore a function call with (a1,a2,...an-1,an) would be 
	 * interpreted with arguments as (a1...an-1) and return value an
         * The sandboxed used below must be a global sandbox across this c++ program
	 * "typeof" will be used find and insert the type (T) of varargs 
	 * into the malloc_in_sandbox<T>	
       	 */
	 auto tainted_a = sandbox.malloc_in_sandbox<int>(1*sizeof(int));
	 memcpy(tainted_a.unverified_safe_pointer_because(1*sizeof(int),"writing to region"), a, 1*sizeof(int));
	 auto tainted_b = sandbox.malloc_in_sandbox<int>(1*sizeof(int));
	 memcpy(tainted_b.unverified_safe_pointer_because(1*sizeof(int),"writing to region"), b, 1*sizeof(int));
	 auto tainted_result = sandbox.malloc_in_sandbox<int>(1);
	 cout << "Calling Unchecked function thorugh Sandbox...\n";
	/* 
	 sandbox.invoke_sandbox_function(unchecked_func, (int*)tainted_a, (int*)tainted_b,
		(int*)tainted_result);
	 */
	 auto result_t = tainted_result.copy_and_verify([](std::unique_ptr<int > val){
	 	if(*val.get() <100)
		{
		   cout << "Within legal return range from the unchecked RLBoxed function...\n";		
		   return std::move(val);
	 	}
	 });

	 //untaint the return result and assign it to result (untainted) memory
	 result = result_t.get();
	 return 1;
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

/*
int main(int argc, char const *argv[]) {
    using std::cout;
    using std::cerr;
  
    //We attempt to use dlopen to get the function reference with just a string
    {
    	cout << "C++ dlopen demo\n\n";

    	// open the library
    	cout << "Opening so_header.so...\n";
    	void* handle = dlopen("./mylib.so", RTLD_LAZY);

    	if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    	}

    	// load the symbol
   	 cout << "Loading symbol hello...\n";
    	typedef void (*hello_t)();

    	// reset errors
    	dlerror();
	
	//define in include/mylib1/
    	std::string yourfunc("hello"); // Here is your function

    	hello_t hello = (hello_t) dlsym(handle, yourfunc.c_str());
    	const char *dlsym_error = dlerror();
    	if (dlsym_error) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error <<
            '\n';
        dlclose(handle);
        return 1;
    	}
    }
  //Now we attempt to sandbox the dlsym returned function
  // Create a new sandbox
  extern rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
  sandbox.create_sandbox();
  printf("*****************Purely Called from Library 1\n");
  // call the library hello function
  sandbox.invoke_sandbox_function(hello);

  // call the add function and check the result:
  sandbox.invoke_sandbox_function(add, 3, 4).copy_and_verify([](unsigned ret){
      printf("Adding (3+4) by calling CheckedC function add from Lib1 = %d\n", ret);
      return ret == 7;
  });
  // call the library echo function by passing tainted string
  const char* helloStr = "Printing this from main.cpp!\n";
  size_t helloSize = strlen(helloStr) + 1;
  auto taintedStr = sandbox.malloc_in_sandbox<char>(helloSize);
  std::strncpy(taintedStr.unverified_safe_pointer_because(helloSize, "writing to region"), helloStr, helloSize);
  cout<<"The string * "<<helloStr<<" * has been loaded to sandbox memory @ address "<< (void*)&taintedStr<<endl;
  sandbox.invoke_sandbox_function(echo, taintedStr);

  //trying to call the above function, but this time I try to crash program from within lib1
  const char* CrashStr = "HESOYAM!";
  size_t CrashSize = strlen(helloStr) + 1;
  auto taintedCrashStr = sandbox.malloc_in_sandbox<char>(CrashSize);
  std::strncpy(taintedCrashStr.unverified_safe_pointer_because(CrashSize, "writing to region"),CrashStr,CrashSize);
  //sandbox.invoke_sandbox_function(echo, taintedCrashStr);

  printf("*****************Purely Called from Library 2\n");
  //register a callback and call it 
  auto cb = sandbox.register_callback(hello_cb);
  sandbox.invoke_sandbox_function(call_cb, cb);
  cb.unregister();
  printf("************Calling a Unchecked Function***\n");

  // destroy sandbox
  sandbox.destroy_sandbox();
    return 0;
}

*/
