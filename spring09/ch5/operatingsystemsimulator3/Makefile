#################################################################
#  Programmer: Eric J Lima                                      #
#                                                               #
#  Program: OS Simulator Version 3                              #
#                                                               #
#  Approximate completion time: 2.5 hours                       #
#################################################################

operate: main.o event_subsystem.o statistical_subsystem.o queue_interface.o heap.o
	gcc -g -o operate -ansi -Wall -lm main.o event_subsystem.o statistical_subsystem.o queue_interface.o heap.o

main.o: main.c
	gcc -g -c -ansi -Wall main.c

heap.o: heap.c heap.h
	gcc -g -c -ansi -Wall heap.c

event_subsystem.o: event_subsystem.c event_subsystem.h
	gcc -g -c -ansi -Wall event_subsystem.c

statistical_subsystem.o: statistical_subsystem.c statistical_subsystem.h
	gcc -g -c -ansi -Wall statistical_subsystem.c

queue_interface.o: queue_interface.c queue_interface.h
	gcc -g -c -ansi -Wall queue_interface.c

clean:
	rm *.o
	operate
