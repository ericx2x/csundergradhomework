########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program  Operating System Simulator                  #
#                                                      #
# Approximate Completion Time: 7 hours                 #
########################################################

operate: eventsubsystem.o queue_interface.o statisticalsubsystem.o
	-gcc -o -ansi -Wall -g operate

eventsubsystem.o: globals.h queue_interface.h statisticalsubsystem.h eventsubsystem.c
	-gcc -c -ansi -Wall -g eventsubsystem.c

queue_interface.o: queue_interface.c queue_interface.h
	-gcc -c -ansi -Wall -g queue_interface.c 

statisticalsubsystem.c: statisticalsubsystem.c statisticalsubsystem.h
	-gcc -c -ansi -Wall -g statisticalsubsystem.c

clean:
	rm *.o
	rm operate
