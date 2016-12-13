########################################################
# Programmer: Eric J Lima                              #
#                                                      #
# Program: Expression Evaluator                        #
#                                                      #
# Approximate Completion Time: 9 hours                 #
########################################################


expr: main.o list.o expressions.o stack_interface.o treeprimitives.o analyzer.o
	gcc -g -o expr -ansi -Wall main.o list.o expressions.o stack_interface.o treeprimitives.o analyzer.o

main.o: main.c tree.c symboltable.h
	gcc -g -c -ansi -Wall main.c tree.c

expressions.o: expressions.c list.h globals.h stack_interface.h expressions.h globals.h tree.c treeprimitives.h tree.h symboltable.h
	gcc -g -c -ansi -Wall expressions.c

list.o: list.c list.h globals.h
	gcc -g -c -ansi -Wall list.c

stack_interface.o: stack_interface.c stack_interface.h stack.h globals.h treeprimitives.h list.h
	gcc -g -c -ansi -Wall stack_interface.c

treeprimitives.o: treeprimitives.c globals.h treeprimitives.h queue.h 
	gcc -g -c -ansi -Wall treeprimitives.c

analyzer.o: analyzer.c globals.h list.h stack.h
	gcc -g -c -ansi -Wall analyzer.c

stack.o: stack.c stack.h globals.h
	gcc -g -c -ansi -Wall stack.c

clean:
	rm *.o expr
