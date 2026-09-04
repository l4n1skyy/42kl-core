NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=4
AR = ar -rcs

SRCS = get_next_line.c \
		get_next_line_utils.c \
       main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
