########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Rational Number Module                      #
#                                                      #
# Approximate Completion Time: 2 hours                 #
########################################################

rational : main.o rational.o
	gcc -o rational main.o rational.o

main.o : main.c
	gcc -c -ansi -Wall main.c

rational.o : rational.c rational.h
	gcc -c -ansi -Wall rational.c

clean :
	rm *.o
	rm rational
