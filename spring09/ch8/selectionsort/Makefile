#######################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program 3: Selection Sort                            #
#                                                      #
# Approximate Completion Time: 6 hours                 #
########################################################

all: words ints

main1.o: main1.c selection.h globals.h
	gcc -c main1.c -words -ansi -Wall -g

main2.o: main2.c selection.h globals.h
	gcc -c main2.c -ints -ansi -Wall -g

selection.o: selection.c globals.h selection.h
	gcc -c selection.c -ansi -Wall -g

clean:
	rm *.o
	rm words
	rm ints
