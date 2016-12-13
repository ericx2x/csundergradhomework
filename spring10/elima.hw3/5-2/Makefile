# Eric Lima
# This is Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ2 = e5.2.o e5.2-book.o e5.2-tbook.o e5.2-rbook.o
e5.2:	$(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) $(CFLAGS) -o e5.2 
e5.2.o:	e5.2.cpp e5.2-book.h e5.2-tbook.h e5.2-rbook.h
	$(CC) $(CFLAGS) -c e5.2.cpp
e5.2-book.o:	e5.2-book.cpp e5.2-book.h
	$(CC) $(CFLAGS) -c e5.2-book.cpp
e5.2-tbook.o:	e5.2-tbook.cpp e5.2-book.h e5.2-tbook.h
	$(CC) $(CFLAGS) -c e5.2-tbook.cpp
e5.2-rbook.o:	e5.2-rbook.cpp e5.2-book.h e5.2-rbook.h
	$(CC) $(CFLAGS) -c e5.2-rbook.cpp
 

