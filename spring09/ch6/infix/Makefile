################################################
#  Programmer: Eric J Lima                     #
#                                              #
#  Program: Infix to Postfix                   #
#                                              #
#  Approximate completion time: 4.5 hours      #
################################################

postfix: main.o token.o char_interface.o stack.o list.o
	gcc -g -o postfix -ansi -Wall main.o char_interface.o token.o stack.o list.o

main.o: main.c
	gcc -g -c -ansi -Wall main.c

token.o: token.c token.h
	gcc -g -c -ansi -Wall token.c

char_interface.o: char_interface.c char_interface.h
	gcc -g -c -ansi -Wall char_interface.c
	
stack.o: stack.c stack.h
	gcc -g -c -ansi -Wall stack.c

list.o: list.c list.h
	gcc -g -c -ansi -Wall list.c
	
clean:
	rm *.o
