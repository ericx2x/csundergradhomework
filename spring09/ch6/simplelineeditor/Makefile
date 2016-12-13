########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Simple Line Editor                          #
#                                                      #
# Approximate Completion Time: 9 hours                 #
########################################################

line: main.o dlist.o user.o
	gcc -o line main.o stack.o -ansi -Wall -g

main.o: globals.h main.c dlists.h
	gcc -c main.c -ansi -Wall -g

dlist.o: dlist.c globals.h dlist.h interface.h
	gcc -c dlist.c -ansi -Wall -g

user.o: user.c globals.h user.h dlists.h interface.h
	gcc -c user.c -ansi -Wall -g
clean:
	rm *.o
	rm line
