################################################
#  Programmer: Eric J Lima                     #
#                                              #
#  Program: Polynomial Addition                #
#                                              #
#  Time to complete: 4 hours                   #
################################################

addpoly: main.o list.o polynomial.o listinterface.o
			gcc -g -o addpoly -ansi -Wall main.o list.o polynomial.o listinterface.o

main.o: main.c polynomial.h globals.h
			gcc -g -c -ansi -Wall main.c

list.o: list.c list.h globals.h
			gcc -g -c -ansi -Wall list.c

polynomial.o: polynomial.c polynomial.h list.h
			gcc -g -c -ansi -Wall polynomial.c

listinterface.o: listinterface.c listinterface.h
			gcc -g -c -ansi -Wall listinterface.c

clean:
			rm *.o addpoly
