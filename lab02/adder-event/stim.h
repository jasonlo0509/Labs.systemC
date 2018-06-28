#ifndef _STIM_H_
#define _STIM_H_

#include <iomanip>
using std::setw;
#include "adder.h"

#define DEPTH (1<<WIDTH)

SC_MODULE(stim) {

	adder dut;

	void stim_gen() {
		for ( int a = 0; a<DEPTH; a++ ) {
			for ( int b = 0; b<DEPTH; b++ ) {
				wait( 1, SC_NS );
				dut.i_a( a );
				dut.i_b( b );
			}
		}
	}

	void monitor() {
		cout<< setw(12)<< "time"<< setw(12)<< "a"<< setw(12)<< "b"<< setw(12)<< "sum"<< endl;
		while ( true ) {
			cout << setw(12) << sc_time_stamp();
			cout << setw(12) << dut.i_a().to_string(SC_BIN);
			cout << setw(12) << dut.i_b().to_string(SC_BIN);
			cout << setw(12) << dut.o_sum().to_string(SC_BIN) << endl;
			wait();
		}
	}

	SC_CTOR(stim): dut( "dut", 1) {
		SC_THREAD( stim_gen );
    
		// the first row of output table
		SC_THREAD( monitor );
		sensitive<< dut.o_sum_changed();
	}
};

#endif
