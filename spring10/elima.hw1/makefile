# makefile for exercises in Chapter 3
# run: make -f 3.make target
# For example:
# make -f 3.make  
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

