########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Set Equal                                   #
#                                                      #
# Approximate Completion Time: 2 hours                 #
########################################################

equal: list.o main2.o
	gcc -g -o equal -ansi -Wall list.o main2.o

main2.o: main2.c list.h
	gcc -g -c -ansi -Wall main2.c

list.o: list.c list.h globals.h
	gcc -g -c -ansi -Wall list.c

clean:
	rm *.o equal
