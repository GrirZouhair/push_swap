# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:51:32 by zogrir            #+#    #+#              #
#    Updated: 2025/03/18 10:55:35 by zogrir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_MANDATORY = MANDATORY/tools/freeing.c MANDATORY/tools/ft_atoi.c MANDATORY/tools/ft_split.c MANDATORY/tools/libft_bonus.c MANDATORY/tools/ft_strjoin.c MANDATORY/tools/ft_positioning.c \
MANDATORY/tools/push.c MANDATORY/tools/parssing.c MANDATORY/tools/valid_num_check.c MANDATORY/tools/ft_indexing.c \
MANDATORY/fill_stack.c MANDATORY/push_swap.c  MANDATORY/ft_sorting_algo.c MANDATORY/rotation.c MANDATORY/ft_swap_four.c MANDATORY/ft_swap_five.c MANDATORY/ft_swap_long_num.c

SRC_BONUS = BONUS/get_next_line/get_next_line_bonus.c BONUS/get_next_line/get_next_line_utils_bonus.c BONUS/tools/check_operations_bonus.c BONUS/tools/freeing_bonus.c BONUS/tools/helper1_bonus.c BONUS/tools/helper2_bonus.c BONUS/tools/helper3_bonus.c \
BONUS/tools/ft_split_bonus.c BONUS/tools/parssing_bonus.c BONUS/tools/helper4_bonus.c BONUS/tools/ft_strjoin_bonus.c BONUS/checker_bonus.c BONUS/ft_swap_s_bonus.c BONUS/rotation_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

all : $(NAME)
bonus : $(NAME_BONUS)

$(NAME) : $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -o $(NAME)
$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJ_MANDATORY) : %.o : %.c ./MANDATORY/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_BONUS) : %.o : %.c ./BONUS/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all