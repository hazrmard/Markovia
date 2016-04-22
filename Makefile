CC=g++
CFLAGS=-Wall -O3 -I inc -lpthread -std=c++0x
BIN=bin
SRC=src
OBJ=obj

all: main

main: helpers
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(OBJ)/*.o -o $(BIN)/Markovia

helpers:
	$(CC) $(CFLAGS) -c $(SRC)/helpers.cpp -o $(OBJ)/helpers.o

clean:
	rm bin/*
	rm obj/*
