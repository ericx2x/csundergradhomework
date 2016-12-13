# Eric Lima
# Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ7 = e3.7.o e3.7-point.o e3.7-cube.o
e3.7:	$(OBJ7)
	$(CC) $(CFLAGS) $(OBJ7) $(CFLAGS) -o e3.7 
e3.7.o:	e3.7.cpp e3.7-point.h e3.7-cube.h
	$(CC) $(CFLAGS) -c e3.7.cpp
e3.7-point.o:	e3.7-point.cpp e3.7-point.h
	$(CC) $(CFLAGS) -c e3.7-point.cpp
e3.7-cube.o:	e3.7-cube.cpp e3.7-cube.h e3.7-point.h
	$(CC) $(CFLAGS) -c e3.7-cube.cpp
