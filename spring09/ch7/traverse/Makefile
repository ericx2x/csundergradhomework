########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Tree Traversal                              #
#                                                      #
# Approximate Completion Time: 8 hours                 #
########################################################

trav : main.o queue.o list.o tree.o treeinterface.o
	gcc -g -o trav main.o queue.o list.o tree.o treeinterface.o

main.o : main.c
	gcc -g -c -ansi -Wall main.c

queue.o : queue.c queue.h
	gcc -g -c -ansi -Wall queue.c

list.o : list.c list.h
	gcc -g -c -ansi -Wall list.c

tree.o : tree.c tree.h
	gcc -g -c -ansi -Wall tree.c

treeinterface.o : treeinterface.c treeinterface.h
	gcc -g -c -ansi -Wall treeinterface.c

clean :
	rm *.o
	rm trav
