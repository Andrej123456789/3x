CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
OBJS = main.o
BIN = main

all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf main main.o
