Player.o: Player.cpp
	g++ Player.cpp -c Player.o

Container.o: Container.cpp Bowl.cpp Dishwasher.cpp Stove.cpp
	g++ Container.cpp Bowl.cpp Dishwasher.cpp Stove.cpp -c Container.o

Resources.o: Resources.cpp
	g++ Resources.cpp -c Resources.o 

Order.o: Order.cpp
	g++ Order.cpp -c Order.o 

main.o: main.cpp
	g++ main.cpp -c main.o 



gameStart: Order.o Player.o Resources.o Container.o 
	g++ Order.o Player.o Resources.o Container.o main.o -o gameStart



clean:
	rm gameStart *.o 
