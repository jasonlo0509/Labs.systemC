all: datatypes.exe

datatypes.exe: datatypes.o
	g++ -L$(SYSTEMC_HOME)/lib-linux64 datatypes.o -lsystemc -lpthread -o datatypes.exe

datatypes.o: datatypes.cpp 
	g++ -c -I$(SYSTEMC_HOME)/include datatypes.cpp

run:
	./datatypes.exe

clean:
	rm *.o datatypes.exe
