#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol

#include <dlfcn.h>
#include <stdio.h>
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
  rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
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
