#Eric Lima

project1: Point.o Sphere.o main.o
	g++ -o project1 Sphere.o Point.o main.o 

Point.o: Point.cpp Point.h
	g++ -c -g -Wall Point.cpp

Sphere.o: Sphere.cpp Sphere.h
	g++ -c -g -Wall Sphere.cpp 

main.o: main.cpp
	g++ -c -g -Wall main.cpp

clean:
	rm *.o
	rm project1
