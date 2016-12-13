#Eric Lima
# Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ7 = e3.6.o e3.6-point.o e3.6-cube.o
e3.6:	$(OBJ7)
	$(CC) $(CFLAGS) $(OBJ7) $(CFLAGS) -o e3.6 
e3.6.o:	e3.6.cpp e3.6-point.h e3.6-cube.h
	$(CC) $(CFLAGS) -c e3.6.cpp
e3.6-point.o:	e3.6-point.cpp e3.6-point.h
	$(CC) $(CFLAGS) -c e3.6-point.cpp
e3.6-cube.o:	e3.6-cube.cpp e3.6-cube.h e3.6-point.h
	$(CC) $(CFLAGS) -c e3.6-cube.cpp
