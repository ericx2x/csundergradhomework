# Eric Lima 
# makefile for exercises in Chapter 6
# run: make -f 6.make target
# For example:
# make -f 6.make  
LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ6 = e6.9.o e6.9-mystring.o 
e6.9:	$(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) $(LIB) -o e6.9
e6.9.o:	e6.9.cpp e6.9-mystring.h  e6.9-mystring-ifc.h
	$(CC) $(CFLAGS) -c e6.9.cpp
e6.9-mystring.o:	e6.9-mystring.cpp e6.9-mystring.h  e6.9-mystring-ifc.h  
	$(CC) $(CFLAGS) -c e6.9-mystring.cpp         
