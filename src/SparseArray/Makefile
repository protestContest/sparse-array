CC = g++
CFLAGS = -Wall -Wextra

TwoDArray.o: TwoDArray.h TwoDArray.cpp Node.o
	$(CC) $(CFLAGS) -c TwoDArray.cpp -o TwoDArray.o
	cp TwoDArray.h ..

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp -o Node.o
	cp Node.h ..

clean:
	rm -rf TwoDArray.o
	rm -rf Node.o
