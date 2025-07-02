NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_DEF = -D BUFFER_SIZE=$(BUFFER_SIZE)

SRC = get_next_line.c get_next_line_utils.c main.c

ifndef BUFFER_SIZE
	BUFFER_DEF =
endif

all:
	$(CC) $(CFLAGS) $(BUFFER_DEF) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
