#####################################################
#  Programmer: Eric J Lima                          #
#                                                   #
#  Program: Polymorphic Ducks and Alligators        #
#                                                   #
#  Approximate completion time: 2 hours             #
#####################################################

ducks: main.o duck.o ducksinterface.o circular.o
	gcc -g -o ducks -ansi -Wall main.o duck.o ducksinterface.o circular.o

main.o: main.c
	gcc -g -c -ansi -Wall main.c

duck.o: duck.c duck.h
	gcc -g -c -ansi -Wall duck.c
	
ducksinterface.o: ducksinterface.c ducksinterface.h
	gcc -g -c -ansi -Wall ducksinterface.c

circular.o: circular.c circular.h
	gcc -g -c -ansi -Wall circular.c
	
clean:
	rm *.o
