########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Merge Sort                                  #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################

merge: main.o merge.o
	gcc -o merge main.o merge.o

main.o: main.c
	gcc -c main.c -ansi -Wall -g

merge.o: merge.c
	gcc -c merge.c -ansi -Wall -g

clean:
	rm *.o
	rm merge
