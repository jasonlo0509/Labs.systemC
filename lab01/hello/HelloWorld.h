#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <systemc>

SC_MODULE (HelloWorld) {

	SC_CTOR (HelloWorld) {
		// Nothing in constructor 
		std::cout << "HelloWorld is constructed" << std::endl;
		SC_METHOD( say_hello );
	}

	void say_hello();
};

#endif
