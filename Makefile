CC = gcc
CFLAGS = -g
.PHONY = all clean
SOURCE = linkedlist_int.c
NAME = run_me

all: $(NAME)

$(NAME): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) $(NAME)
