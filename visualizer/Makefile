CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g -lgmp
OBJS = ../executable/visualizer.o
BIN = ../executable/visualizer

all : $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

../executable/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ../executable/visualizer *.o