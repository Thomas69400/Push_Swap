CC = cc

CFLAGS = -Werror -Wall -Wextra

UTILS_DIR = utils/
ALGO_DIR = algos/

SRCS = main.c \
ft_atoi.c \
ft_sqrt.c \
ft_bzero.c \
ft_calloc.c \
ft_strcmp.c \
init_data.c \
ft_printf.c \
push.c \
reverse.c \
rotate.c \
swap.c \
disorder.c \
benchmark.c \
$(UTILS_DIR)nbr_utils.c \
$(UTILS_DIR)lst_utils.c \
$(UTILS_DIR)lst_utils_bis.c \
$(UTILS_DIR)error_utils.c \
$(UTILS_DIR)algos_utils.c \
$(ALGO_DIR)simple.c \
$(ALGO_DIR)medium.c \
$(ALGO_DIR)complex.c \
$(ALGO_DIR)adaptive.c \

HEADERS = push_swap.h \
ft_printf.h

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re