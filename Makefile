CC=gcc
CFLAGS=-Wall -O3 -I inc/
BIN=bin
SRC=src

all: main

main:
	$(CC) $(CFLAGS) $(SRC)/main.c -o $(BIN)/Markovia

clean:
	rm bin/*
	rm obj/*
