# Eric Lima
# Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ8 = e3.8.o e3.8-employee.o e3.8-company1.o e3.8-company2.o
e3.8:   $(OBJ8)
	$(CC) $(CFLAGS) $(OBJ8) $(LIB) -o e3.8
e3.8.o: e3.8.cpp e3.8-employee.h
	$(CC) $(CFLAGS) -c e3.8.cpp
e3.8-employee.o:        e3.8-employee.cpp e3.8-employee.h
	$(CC) $(CFLAGS) -c e3.8-employee.cpp         
e3.8-company1.o:        e3.8-company1.cpp e3.8-company1.h e3.8-employee.h
	$(CC) $(CFLAGS) -c e3.8-company1.cpp  
e3.8-company2.o:        e3.8-company2.cpp e3.8-company2.h e3.8-employee.h
	$(CC) $(CFLAGS) -c e3.8-company2.cpp  

