#########################################
#  Programmer: Eric J Lima              #
#                                       #
#  Program: Graphical Region Fill       #
#                                       #
#  Completion Time: 3 hours             #
#########################################

fill: main.o stack.o interface.o image.o
	gcc -g -o fill -ansi -Wall main.o stack.o interface.o image.o

main.o: main.c globals.h
	gcc -g -c -ansi -Wall main.c

image.o: image.c globals.h
	gcc -g -c -ansi -Wall image.c
	
stack.o: stack.c stack.h globals.h
	gcc -g -c -ansi -Wall stack.c

interface.o: interface.c interface.h globals.h
	gcc -g -c -ansi -Wall interface.c

clean:
	rm *.o
