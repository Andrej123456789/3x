CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
LDFLAGS = -lgmp

OBJDIR = objects
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))

BINFOLDER = executable
BIN = $(BINFOLDER)/3x

all : $(OBJDIR) $(BINFOLDER) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINFOLDER):
	mkdir $(BINFOLDER)

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	@./$(BIN)

clean:
	rm -rf $(OBJDIR) $(BINFOLDER)
