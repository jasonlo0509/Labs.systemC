#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"

#define WIDTH  2

class adder: public sc_module {
public:
  void do_add() {
    _o_sum = ( _i_a + _i_b );
		_o_sum_changed.notify();
  }

  SC_HAS_PROCESS( adder );
  adder( sc_module_name name, int i ): id( i ) {
    SC_METHOD(do_add);   
    sensitive << _i_a_changed << _i_b_changed; 
  }

	sc_uint<WIDTH> i_a() { return _i_a; }
	void i_a( sc_uint<WIDTH> a ) { _i_a = a; _i_a_changed.notify(); }
	sc_uint<WIDTH> i_b() { return _i_b; }
	void i_b( sc_uint<WIDTH> b ) { _i_b = b; _i_b_changed.notify(); }
	sc_uint<WIDTH+1> o_sum() { return _o_sum; }

	const sc_event& o_sum_changed() { return _o_sum_changed; }

private:
	const int id;
  sc_uint<WIDTH> _i_a;
	sc_uint<WIDTH> _i_b;  
  sc_uint<WIDTH+1> _o_sum;

	sc_event _i_a_changed;
	sc_event _i_b_changed;
	sc_event _o_sum_changed;

};

#endif
