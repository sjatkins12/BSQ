NAME = bsq

CC = gcc

CFLAGS += -Wall -Wextra -Werror -c

CFLAGS2 = -Wall -Wextra -Werror -O3 -o

SRCS = main.c \
	box_opps.c \
	helper.c

OBJ = main.o \
	  box_opps.o \
	  helper.o

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^
	$(CC) $(CFLAGS2) $@ $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

