#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_noop_sandbox_lookup_symbol

#include <stdio.h>
#include <iostream>
//#include "mylib.h"
#include "mylibheader.hpp"
#include "../../code/include/rlbox.hpp"
#include "../../code/include/rlbox_noop_sandbox.hpp"

using namespace rlbox;

int main(int argc, char const *argv[]) {
  // Create a new sandbox
  rlbox::rlbox_sandbox<rlbox_noop_sandbox> sandbox;
  sandbox.create_sandbox();

  // call the library hello function
  sandbox.invoke_sandbox_function(hello);

  // call the add function and check the result:
  auto ok = sandbox.invoke_sandbox_function(add, 3, 4).copy_and_verify([](unsigned ret){
      printf("Adding... 3+4 = %d\n", ret);
      return ret == 7;
  });
  printf("OK? = %d\n", ok);

  // call the library echo function
  const char* helloStr = "hi hi!";
  size_t helloSize = strlen(helloStr) + 1;
  auto taintedStr = sandbox.malloc_in_sandbox<char>(helloSize);
  std::strncpy(taintedStr.unverified_safe_pointer_because(helloSize, "writing to region"), helloStr, helloSize);
  sandbox.invoke_sandbox_function(echo, taintedStr);
  sandbox.free_in_sandbox(taintedStr);

  // destroy sandbox
  sandbox.destroy_sandbox();

  return 0;
}
