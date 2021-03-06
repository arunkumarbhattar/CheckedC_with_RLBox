#include "rlbox_basic_headers.hpp"
#include "../include/library_3/lib.h"
#include "../include/library_3/lib_struct_file.h"
#include "../include/library_3/tainted_sub_functions.hpp"

using namespace rlbox;
using namespace std;

using rlbox_sandbox_type = rlbox::rlbox_noop_sandbox;
using rlbox_sandbox_lib = rlbox::rlbox_sandbox<rlbox_sandbox_type>;
template<typename T>
using tainted_img = tainted<T, rlbox_sandbox_type>;

rlbox_load_structs_from_library(lib);

//we need to have a global static sandbox created
extern rlbox::rlbox_sandbox<rlbox_sandbox_type>* sandbox_chk_2_unchk = new rlbox_sandbox_lib();

extern "C" void CreateSandbox()
{
         sandbox_chk_2_unchk->create_sandbox();
	 return;
}

void DeleteSandbox (rlbox_sandbox_lib *sandbox) {
         sandbox->destroy_sandbox();
         delete sandbox;
}

extern "C" int invoked_unchecked_function(char* func_name, int* a, int*b, int* result)
{
	if(execute_unchecked_function(func_name, a, b, result))
		return 1;
	else
		return 0;
}

char* test(char*);
int invoke_unchecked_print_function(char* func_name, char* output)
{
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
        
        	/*we can have verifier checks for the following here -->
		First, if the tainted pointer is null.
   		Second, if the tainted pointer is out-of-bounds.
   		Third, checking the pointer type hierarchy in heap.
		*/
	        cerr << "Illegal memory pointing char* returned \n";
	     }
	     return std::move(val);
         });
         
         //untaint the return result (which is in stack memory) and copy it to result (untainted) in Heap memory
         strncpy(output, result_t.get(), strlen(result_t.get()));
	 return true;
}

//this is a dummy function definition to enable compilation. 
int* tempptr(int*, int*);

bool execute_unchecked_function(char* func_name, int* a, int* b, int* result)
{
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
	 //Can you deference the pointer allocated within the host
	 rlbox::memcpy(*sandbox_chk_2_unchk, t_a, a, 1);
	 rlbox::memcpy(*sandbox_chk_2_unchk, t_b, b, 1);
	 cout << "Calling Unchecked function thorugh Sandbox...\n";
	 //*******what happens when t_a or t_b is outside sandboxed memory
	 auto t_result = sandbox_chk_2_unchk->invoke_sandbox_function_ptr(tempptr, unchecked_func, t_a, t_b);
	 auto result_t = t_result.copy_and_verify([](std::unique_ptr<int > val){
	 if(*val.get() <100)
	 {
	 	//******let the function return some random address and see what happens
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
	 return true;
}

