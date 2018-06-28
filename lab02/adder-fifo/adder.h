#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"

#define WIDTH  2

class adder: public sc_module {
public:
  void do_add() {
		while ( true ) {
			if ( fifo_i_a.num_available() > 0 && fifo_i_b.num_available() > 0 ) {
				wait( 2, SC_NS );
				_i_a = fifo_i_a.read();
				_i_b = fifo_i_b.read();
				fifo_o_sum.write( _i_a + _i_b );
			}
			else {
				if ( fifo_i_a.num_available() < 1 && fifo_i_b.num_available() < 1 ) {
					wait( fifo_i_a.data_written_event() & fifo_i_b.data_written_event() );
				}
				else if ( fifo_i_a.num_available() < 1 ) {
					wait( fifo_i_a.data_written_event() );
				}
				else {
					wait( fifo_i_b.data_written_event() );
				}
			}
		}
  }

  SC_HAS_PROCESS( adder );
  adder( sc_module_name name, int i ): id( i ) {
    SC_THREAD(do_add);   
  }

	sc_uint<WIDTH> i_a() { return _i_a; }
	void i_a( sc_uint<WIDTH> a ) { fifo_i_a.write( a ); }
	sc_uint<WIDTH> i_b() { return _i_b; }
	void i_b( sc_uint<WIDTH> b ) { fifo_i_b.write( b ); }
	sc_uint<WIDTH+1> o_sum() { return fifo_o_sum.read(); }

	const sc_event& o_sum_changed() { return fifo_o_sum.data_written_event(); }

private:
	const int id;
  sc_uint<WIDTH> _i_a;
	sc_uint<WIDTH> _i_b;  
  sc_fifo< sc_uint<WIDTH> > fifo_i_a;
	sc_fifo< sc_uint<WIDTH> > fifo_i_b;  
  sc_fifo< sc_uint<WIDTH+1> > fifo_o_sum;

	sc_event _i_a_changed;
	sc_event _i_b_changed;
	sc_event _o_sum_changed;

};

#endif
