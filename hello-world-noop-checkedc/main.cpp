#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol

#include <stdio.h>
#include <iostream>
//include the c++ header file that provides
//interface for all libraries
#include "mylibheader.hpp"
#include "../../code/include/rlbox.hpp"
#include "../../code/include/rlbox_noop_sandbox.hpp"
#include "lib_struct_file.h"
using namespace rlbox;

tainted<int, rlbox_noop_sandbox> hello_cb(rlbox_sandbox<rlbox_noop_sandbox>& _,
              tainted<const char*, rlbox_noop_sandbox> str) {
  auto checked_string =
    str.copy_and_verify_string([](std::unique_ptr<char[] > val) {
        printf("Length of the string is: %d, ", strlen(val.get()));
  	return strlen(val.get()) < 1024 ? std::move(val) : nullptr;
    });
  printf(" and the string is: %s\n", checked_string.get());
  return 1;
}

int main(int argc, char const *argv[]) {
  // Create a new sandbox
  rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
  sandbox.create_sandbox();
  printf("*****************Purely Called from Library 1\n");
  // call the library hello function
  sandbox.invoke_sandbox_function(hello);

  // call the add function and check the result:
  auto ok = sandbox.invoke_sandbox_function(add, 3, 4).copy_and_verify([](unsigned ret){
      printf("Adding... 3+4 = %d\n", ret);
      return ret == 7;
  });
  // call the library echo function
  const char* helloStr = "hey, whats up!\n";
  size_t helloSize = strlen(helloStr) + 1;
  auto taintedStr = sandbox.malloc_in_sandbox<char>(helloSize);
  std::strncpy(taintedStr.unverified_safe_pointer_because(helloSize, "writing to region"), helloStr, helloSize);
  sandbox.invoke_sandbox_function(echo, taintedStr);

  printf("*****************Purely Called from Library 2\n");
  //register a callback and call it 
  auto cb = sandbox.register_callback(hello_cb);
  sandbox.invoke_sandbox_function(call_cb, cb);
  cb.unregister();
  // destroy sandbox
  sandbox.destroy_sandbox();

  return 0;
}
