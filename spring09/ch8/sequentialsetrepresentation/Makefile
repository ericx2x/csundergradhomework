########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program 2: Sequential Set                            #
#                                                      #
# Approximate Completion Time: 6 hours                 #
########################################################

all: myss1 myss2

main1.o: main1.c set.c set.h globals.h
	gcc -c main1.c -myss1 -ansi -Wall -g

main2.o: main2.c set.c set.h globals.h
	gcc -c main2.c -myss2 -ansi -Wall -g

set.o: set.c globals.h set.h
	gcc -c set.c -ansi -Wall -g

clean:
	rm *.o
	rm myss1
	rm myss2
