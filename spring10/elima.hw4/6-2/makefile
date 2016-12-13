# Eric Lima
# Makefile for Exercise 6-2

prog: main.o intstack.o
	g++ -o prog main.o intstack.o

main.o: main.cpp
	g++ -c main.cpp

intstack.o: intstack.cpp intstack.h
	g++ -c intstack.cpp

clean:
	rm *.o
	rm 6-2
