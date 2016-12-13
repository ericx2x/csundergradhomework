########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Parenthesis Checker                         #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################


treewalk: main.o treeinterface.o tree.o queue.o list.o
	gcc -g -o treewalk -ansi -Wall -lm main.o treeinterface.o tree.o queue.o list.o

treeinterface.o: treeinterface.c
	gcc -g -c -ansi -Wall treeinterface.c
	
main.o: main.c
	gcc -g -c -ansi -Wall main.c

tree.o: tree.c
	gcc -g -c -ansi -Wall tree.c

queue.o: queue.c
	gcc -g -c -ansi -Wall queue.c

list.o: list.c
	gcc -g -c -ansi -Wall list.c

clean:
	rm *.o
	treewalk
