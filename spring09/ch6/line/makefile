########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Simple Line Editor                          #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################

line : main.o dlists.o user.o
	gcc -o line main.o dlists.o user.o

main.o : main.c
	gcc -c -ansi -Wall main.c

user.o : user.c user.h
	gcc -c -ansi -Wall user.c

dlists.o : dlists.c dlists.h
	gcc -c -ansi -Wall dlists.c

clean :
	rm *.o
	rm line
