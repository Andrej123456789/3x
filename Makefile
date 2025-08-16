CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
LDFLAGS = -lgmp

BIN_FOLDER = executable
OBJS = $(BIN_FOLDER)/main.o
BIN = $(BIN_FOLDER)/main

all : $(BIN_FOLDER) $(BIN)

$(BIN_FOLDER):
	mkdir executable

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

executable/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf executable/*

python:
	python3 main.py
