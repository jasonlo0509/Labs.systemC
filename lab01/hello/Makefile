all: hello.exe

hello.exe: HelloWorld.o main.o
	g++ -L$(SYSTEMC_HOME)/lib-linux64 main.o HelloWorld.o -lsystemc -o hello.exe

HelloWorld.o: HelloWorld.cpp HelloWorld.h
	g++ -c -I$(SYSTEMC_HOME)/include HelloWorld.cpp

main.o: main.cpp HelloWorld.h
	g++ -c -I$(SYSTEMC_HOME)/include main.cpp
clean:
	rm HelloWorld.o main.o hello.exe
