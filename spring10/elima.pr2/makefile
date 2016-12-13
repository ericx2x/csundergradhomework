# Eric Lima

project2: main.o node.o tree.o
	g++ -o project2 main.o node.o tree.o

main.o: main.cpp
	g++ -c main.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

tree.o: tree.cpp tree.h
	g++ -c tree.cpp

clean:
	rm *.o
	rm project2
