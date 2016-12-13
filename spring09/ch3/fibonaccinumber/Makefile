########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Fibonacci Frequency                         #
#                                                      #
# Approximate Completion Time: 6 hours                 #
########################################################


frequency : main.o fibonacci.o
	gcc -g -o frequency main.o fibonacci.o

main.o : main.c
	gcc -c -g -ansi -Wall main.c

fibonacci.o : fibonacci.c fibonacci.h
	gcc -c -g -ansi -Wall fibonacci.c

clean :
	rm *.o
	rm frequency
