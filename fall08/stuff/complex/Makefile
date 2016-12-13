#####################################################
#  Programmer: Eric J Lima                          #
#                                                   #
#  Program: Complex Number Module (extended)        #
#                                                   #
#  Approximate completion time: 1 hour              #
#####################################################

complex: complex.o
	gcc -g -o complex -ansi -Wall complex.o

complex.o: complex.c complex.h
	gcc -g -c -ansi -Wall complex.c

clean:
	rm *.o complex
