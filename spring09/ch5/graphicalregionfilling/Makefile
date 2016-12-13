########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Graphical Region Filling                    #
#                                                      #
# Approximate Completion Time: 11 hours                #
########################################################

fill: main.o fill.o image.o stackinterface.o stack.o
	gcc -ansi -Wall -g -o fill main.o fill.o image.o stackinterface.o stack.o

main.o: main.c fill.h image.h fill.h
	gcc -c main.c -ansi -Wall -g 

fill.o: fill.c fill.h stackinterface.h stack.h image.h globals.h
	gcc -c fill.c -ansi -Wall -g

image.o: image.c image.h globals.h
	gcc -c image.c -ansi -Wall -g 

stackinterface.o: stackinterface.c stackinterface.h globals.h
	gcc -c stackinterface.c -ansi -Wall -g

stack.o: stack.c stack.h globals.h
	gcc -c stack.c -ansi -Wall -g

clean:
	rm *.o
	rm fill
