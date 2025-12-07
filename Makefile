CC = cc

CFLAGS = -Werror -Wall -Wextra -g3

SRCS = main.c \
ft_atoi.c \
error_utils.c \
ft_printf.c \
lst_utils.c \
push.c \
reverse.c \
rotate.c \
sort_lst.c \
swap.c 

HEADERS = push_swap.h \
ft_printf.h

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re