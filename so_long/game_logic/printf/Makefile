NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_hexlen.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putnbr_unsigned.c ft_voidptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
