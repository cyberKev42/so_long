# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:08:46 by kbrauer           #+#    #+#              #
#    Updated: 2023/11/23 14:38:20 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -lXext

SRCS_DIR = ./game_logic
PRINTF_DIR = ./game_logic/printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS = $(SRCS_DIR)/check_error.c \
		$(SRCS_DIR)/controls.c \
		$(SRCS_DIR)/ft_itoa.c \
		$(SRCS_DIR)/get_next_line_bonus.c \
		$(SRCS_DIR)/get_next_line_utils_bonus.c \
		$(SRCS_DIR)/init_main.c \
		$(SRCS_DIR)/load_img.c \
		$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/map_data.c \
		$(SRCS_DIR)/stats.c
	
OBJS = $(SRCS:.c=.o)

.c.o:
	cc $(CFLAGS) -I headers -c $< -o $(<:.c=.o)

$(NAME): $(PRINTF) $(OBJS)
		cc  $(LFLAGS) -o $@ $(OBJS) -L. ./game_logic/printf/libftprintf.a

$(PRINTF):
		make -C $(PRINTF_DIR) all

all: $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) clean
	rm -f $(NAME) ./game_logic/printf/libftprintf.a

re: fclean all

.PHONY: all, clean, fclean, re