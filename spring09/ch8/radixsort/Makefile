########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program : Radix Sort                                 #
#                                                      #
# Approximate Completion Time: 6 hours                 #
########################################################

radix: main.o list.o numberinterface.o
	gcc -o radix main.o list.o numberinterface.o

main.o: numberinterface.h list.o
	gcc -c  main.c -ansi -Wall -g

list.o: globals.h list.h
	gcc -c list.c -ansi -Wall -g

numberinterface.o: numberinterface.h globals.h list.h
	gcc -c numberinterface.c -ansi -Wall -g

clean:
	rm *.o
	rm radix
