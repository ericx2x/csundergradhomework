# Eric Lima

stack: intstackA.o intstackL.o main.o node.o
	g++ -o stack main.o intstackA.o intstackL.o node.o

main.o: main.cpp intstackA.h intstackL.h node.h
	g++ -c main.cpp

intstackA.o: intstackA.cpp intstackA.h
	g++ -c intstackA.cpp

intstackL.o: intstackL.cpp intstackL.h node.h
	g++ -c intstackL.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

clean:
	rm *.o
	rm stack
