########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Dijkstra's Shortest Path                    #
#                                                      #
# Approximate Completion Time: 3 hours                 #
########################################################

dijkstra: graph.o dijkstramain.o
	gcc -o dijkstra dijkstramain.o graph.o -ansi -Wall -g

dijkstramain.o: dijkstramain.c graph.h globals.h 
	gcc -c dijkstramain.c -ansi -Wall -g

graph.o: graph.c graph.h globals.h
	gcc -c graph.c -ansi -Wall -g

clean:
	rm *.o
	rm dijkstra
