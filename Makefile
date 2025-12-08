CC = cc

CFLAGS = -g3 #-Werror -Wall -Wextra 

SRCS = main.c \
ft_atoi.c \
ft_strncmp.c \
error_utils.c \
ft_printf.c \
lst_utils.c \
lst_utils_bis.c \
push.c \
reverse.c \
rotate.c \
sort_lst.c \
sort_lst_utils.c \
swap.c 

HEADERS = push_swap.h \
ft_printf.h

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS) Makefile $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re