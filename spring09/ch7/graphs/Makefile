########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Graph Primitves                             #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################


graph: main.o graph.o
	gcc -g -o treewalk -ansi -Wall -lm main.o graph.o

graph.o: graph.c graph.h globals.h
	gcc -g -c -ansi -Wall graph.c

main.o: main.c treeprimitives.h treeinterface.h
	gcc -g -c -ansi -Wall main.c

clean:
	rm *.o
	graph
