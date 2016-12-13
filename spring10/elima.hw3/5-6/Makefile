# Eric Lima
# This is Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ6 = e5.6.o e5.6-address.o e5.6-address-extended.o e5.6-address-post.o
e5.6:   $(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) $(LIB) -o e5.6
e5.6.o: e5.6.cpp e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6.cpp
e5.6-address.o:        e5.6-address.cpp e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address.cpp         
e5.6-address-extended.o:        e5.6-address-extended.cpp e5.6-address-extended.h e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address-extended.cpp  
e5.6-address-post.o:	e5.6-address-post.cpp e5.6-address-post.h e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address-post.cpp


