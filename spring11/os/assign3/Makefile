#Eric Lima
#Makefile

proddonuts consdonuts: donuts.h proddonuts.o consdonuts.o utilities.o
	cc -o proddonuts proddonuts.o utilities.o
	cc -o consdonuts consdonuts.o utilities.o

consdonuts.o: donuts.h consdonuts.c
	cc -c consdonuts.c

proddonuts.o: donuts.h proddonuts.c
	cc -c proddonuts.c

utilities.o:  utilities.c
	cc -c utilities.c
clean:

	
	rm *.o proddonuts consdonuts
	rm *.txt c1 c2 c3 c4 c5
	rm *~
