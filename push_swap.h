/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 12:27:43 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>

typedef struct s_list
{
	int		content;
	int		position;
	int		index;
	struct	s_list *next;
} t_list;


// utils
char		**ft_split(char const *s, char c);
void		ft_free(char **arr);
int			ft_len(const char *s, char c);
// handle error
int			ft_valid_num_check(const char *str);
int			ft_dup_check(int *numbers, int n);
// stack initialization

//stack utils

//commands




#endif