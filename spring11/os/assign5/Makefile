#
# Eric Lima
#

assign5: firstfit.o bestfit.o print.o main.o buddy.o
	gcc -o assign5 -g -lm firstfit.o bestfit.o print.o main.o buddy.o

buddy.o: buddy.c buddy.h
	cc -c -g buddy.c

firstfit.o: firstfit.c firstfit.h
	gcc -c -g firstfit.c

bestfit.o: bestfit.c bestfit.h
	gcc -c -g bestfit.c

print.o: print.h print.c
	cc -c -g print.c

main.o: main.c
	cc -c -g main.c

clean:
	rm assign5
	rm *.o
	rm *~
