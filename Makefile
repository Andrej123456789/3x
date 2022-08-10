CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g -lgmp
OBJS = executable/main.o
BIN = executable/main

all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

executable/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf executable/*

python:
	python3 main.py