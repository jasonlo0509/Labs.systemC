//systemc.h header file
#include "HelloWorld.h"
using namespace sc_core;

int sc_main(int argc, char* argv[]) {
  HelloWorld hello("hello");
  // Print the hello world
  sc_start();
  return(0);
}
