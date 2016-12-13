########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Parenthesis Checker                         #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################

pc: main.o stack.o
	gcc -o pc main.o stack.o -ansi -Wall -g

main.o: stack.h globals.h main.c
	gcc -c main.c -ansi -Wall -g

stack.o: stack.c globals.h stack_interface.h
	gcc -c stack.c -ansi -Wall -g

clean:
	rm *.o
	rm pc
