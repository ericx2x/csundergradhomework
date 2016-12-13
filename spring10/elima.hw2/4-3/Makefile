# Eric Lima
# Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ3 = e4.3.o e4.3-integer.o 
e4.3:	$(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) $(CFLAGS) -o e4.3 
e4.3.o:	e4.3.cpp e4.3-integer.h 
	$(CC) $(CFLAGS) -c e4.3.cpp
e4.3-integer.o:	e4.3-integer.cpp e4.3-integer.h
	$(CC) $(CFLAGS) -c e4.3-integer.cpp
