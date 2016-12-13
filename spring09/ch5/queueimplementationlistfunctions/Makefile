########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Queue Implementation                        #
#                                                      #
# Approximate Completion Time: 1 hour                  #
########################################################


queue: testqueue.o queue.o list.o
	gcc -g -o queue -ansi -Wall testqueue.o queue.o list.o

queue.o: queue.h globals.h queue.c
	gcc -g -c -ansi -Wall queue.c 

testqueue.o: queue.h globals.h testqueue.c
	gcc -g -c -ansi -Wall testqueue.c

list.o: globals.h list.h list.c
	gcc -g -c -ansi -Wall list.c

clean:
	rm *.o queue
