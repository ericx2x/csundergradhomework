# Eric Lima
# Muldner's Makefile

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

OBJ9 = e4.9.o e4.9-student.o e4.9-student-stack.o
e4.9:   $(OBJ9)
	$(CC) $(CFLAGS) $(OBJ9) $(LIB) -o e4.9
e4.9.o: e4.9.cpp e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9.cpp
e4.9-student.o:        e4.9-student.cpp e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9-student.cpp         
e4.9-student-stack.o:        e4.9-student-stack.cpp e4.9-student-stack.h e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9-student-stack.cpp  

