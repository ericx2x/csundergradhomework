########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Complex Number Module                       #
#                                                      #
# Approximate Completion Time: 1 hour                  #
########################################################

complex: main.o complex.o
	gcc -o complex main.o complex.o -ansi -Wall -g

main.o: globals.h main.c
	gcc -c main.c -ansi -Wall -g

complex.o: complex.c globals.h complex.h
	gcc -c complex.c -ansi -Wall -g

clean:
	rm *.o
	rm pc
