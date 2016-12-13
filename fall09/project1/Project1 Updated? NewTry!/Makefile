#########################################
#  Eric Lima                            #
#                                       #
#  Project1                             #
#                                       #
#  November 19, 2009                    #
#########################################


proj1: main.o Point.o ArrayHolder.o Rectangle.o
	g++ -o proj1 main.o Point.o ArrayHolder.o Rectangle.o

main.o: main.cc
	g++ -c main.cc

Point.o: Point.cc Point.h
	g++ -c Point.cc

ArrayHolder.o: ArrayHolder.cc ArrayHolder.h
	g++ -c ArrayHolder.cc

Rectangle.o: Rectangle.cc Rectangle.h
	g++ -c Rectangle.cc

clean:
	rm *.o
