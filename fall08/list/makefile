addpoly: list.o listinterface.o main.o polynomial.o
	gcc -g -o -ansi -Wall addpoly list.o listinterface.o main.o polynomial.o
list.o: list.c list.h globals.h
	gcc -g -c -ansi -Wall list.c
main.o: globals.h polynomial.h
	gcc -g -c -ansi -Wall main.c
polynomial.o: polynomial.h list.h listinterface.h
	gcc -g -c -ansi -Wall polynomial.c
listinterface.o : globals.h listinterface.h list.h listinterface.c polynomial.h
	gcc -g -c -ansi -Wall listinterface.c
clean:
	rm *.o addpoly
