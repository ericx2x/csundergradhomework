########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Bit Vector                                  #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################

bitvector: main.o bitvector.o
	gcc -o bitvector main.o bitvector.o

main.o: main.c bitvector.h
	gcc -c main.c -ansi -Wall -g 

bitvector.o: bitvector.c globals.h bitvector.h
	gcc -c bitvector.c -ansi -Wall -g

clean:
	rm *.o
	rm bitvector
