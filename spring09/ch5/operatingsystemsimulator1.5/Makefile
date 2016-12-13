#################################################################
#  Programmer: Eric J Lima                                      #
#                                                               #
#  Program: OS Simulator                                        #
#                                                               #
#  Approximate completion time: 3.5 hours                       #
#################################################################

operate: main.o event_subsystem.o statistical_subsystem.o job_interface.o queue.o list.o
	gcc -g -o operate -ansi -Wall -lm main.o event_subsystem.o statistical_subsystem.o job_interface.o queue.o list.o

main.o: main.c
	gcc -g -c -ansi -Wall main.c

event_subsystem.o: event_subsystem.c event_subsystem.h
	gcc -g -c -ansi -Wall event_subsystem.c

statistical_subsystem.o: statistical_subsystem.c statistical_subsystem.h
	gcc -g -c -ansi -Wall statistical_subsystem.c

job_interface.o: job_interface.c job_interface.h job.h
	gcc -g -c -ansi -Wall job_interface.c

queue.o: queue.c queue.h
	gcc -g -c -ansi -Wall queue.c

list.o: list.c list.h
	gcc -g -c -ansi -Wall list.c

clean:
	rm *.o
	rm operate
