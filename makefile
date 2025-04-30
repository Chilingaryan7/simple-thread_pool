#! /bin/bash
main: main.o implementation.o
	g++ -std=c++20 main.o implementation.o -o main

main.o: main.cpp header.hpp
	g++ -std=c++20 main.cpp -c

implementation.o: implementation.cpp header.hpp
	g++ -std=c++20 implementation.cpp -c

clean:
	rm *.o main 
