# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:51:32 by zogrir            #+#    #+#              #
#    Updated: 2025/01/21 13:23:52 by zogrir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_MANDATORY = tools/freeing.c tools/ft_atoi.c tools/ft_split.c tools/libft_bonus.c tools/ft_strjoin.c \
parssing.c fill_stack.c push_swap.c valid_num_check.c ft_swap_two_numbers.c ft_sort_numbers.c

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_MANDATORY)
fclean:clean
	rm -rf $(NAME)
re: fclean all
