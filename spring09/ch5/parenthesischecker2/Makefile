############################################
#  Programmer: Eric J Lima                 #
#                                          #
#  Program: Parenthesis Checker            #
#                                          #
#  Approximate time to complete: 3 hours   #
############################################

paren: main.o stack.o stack_interface.o
			gcc -g -o paren -ansi -Wall main.o stack.o stack_interface.o

main.o: main.c globals.h
			gcc -g -c -ansi -Wall main.c

stack.o: stack.c stack.h globals.h
			gcc -g -c -ansi -Wall stack.c

stack_interface.o: stack_interface.c stack_interface.h globals.h
			gcc -g -c -ansi -Wall stack_interface.c

clean:
			rm *.o
