PHONY: all  clean
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)
BIN=$(OBJ:%.o=%)
 
CC=gcc
CFLAGS=-Wall -g -c

all:$(BIN)
 
$(BIN):%:%.o
	$(CC) $^ -o $@
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) $^ -o $@
 
clean:
	rm $(OBJ) $(BIN)