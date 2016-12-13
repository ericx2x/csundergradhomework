#Eric Lima
#Project 1

project3: main.o node.o tree.o treeADT.o treeIFC.o
	g++ -o project3 main.o node.o tree.o treeADT.o treeIFC.o

main.o: main.cpp
	g++ -c -Wall main.cpp

tree.o: tree.cpp
	g++ -c -Wall tree.cpp

node.o: node.cpp
	g++ -c -Wall node.cpp

treeADT.o: treeADT.cpp
	g++ -c -Wall treeADT.cpp

treeIFC.o: treeIFC.cpp
	g++ -c -Wall treeIFC.cpp

clean:
	rm *.o
	rm project3
