#! /bin/bash
main: mian.o implementation.o
	g++ -std=c++23 mian.o implementation.o -o main

main.o: mian.cpp header.hpp
	g++ -std=c++23 mian.cpp -c

implementation.o: implementation.cpp header.hpp
	g++ -std=c++23 implementation.cpp -c

clean:
	rm *.o main 