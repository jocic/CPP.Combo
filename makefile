CC=g++
CFLAGS=-Wall -g -o bin/test

all:
	$(CC) $(CFLAGS)
		src/combo.h src/combo.cpp
		src/main.cpp
