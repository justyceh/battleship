battleship: main.o ship.o abstractplayer.o game.o
	g++ -o battleship main.o ship.o abstractplayer.o game.o
ship.o: ship.h ship.cpp coordinate.h
	g++ -c ship.cpp 
main.o: main.cpp
	g++ -c main.cpp
abstractplayer.o: abstractplayer.h abstractplayer.cpp
	g++ -c abstractplayer.cpp
game.o: game.h game.cpp
	g++ -c game.cpp		
clean:
	rm *.o battleship	