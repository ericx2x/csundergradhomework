# Michael Staub, Makefile for Evil Snakes

CC = g++
CFLAGS = -g -Wall

OBJ = main.o game.o drawEngine.o sprite.o level.o character.o enemy.o mage.o fireball.o

evilsnakes: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -l ncurses -o evilsnakes 

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp

drawEngine.o: drawEngine.cpp drawEngine.h
	$(CC) $(CFLAGS) -c drawEngine.cpp

sprite.o: sprite.cpp sprite.h
	$(CC) $(CFLAGS) -c sprite.cpp

level.o: level.cpp level.h
	$(CC) $(CFLAGS) -c level.cpp

character.o: character.cpp character.h
	$(CC) $(CFLAGS) -c character.cpp

enemy.o: enemy.cpp enemy.h
	$(CC) $(CFLAGS) -c enemy.cpp

mage.o: mage.cpp mage.h
	$(CC) $(CFLAGS) -c mage.cpp

fireball.o: fireball.cpp fireball.h
	$(CC) $(CFLAGS) -c fireball.cpp

clean:
	rm *.o
	rm evilsnakes
