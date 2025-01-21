/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/21 13:22:35 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>
typedef struct s_list
{
	int		content;
	int		position;
	int		index;
	struct	s_list *next;
} t_list;

#define SA 0
#define SB 1
#define SS 2
#define RA 3
#define RB 4
#define RR 5

// utils
char		**ft_split(char const *s, char c);
int			ft_len(const char *s, char c);
int			ft_atoi(const char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(int size, char **strs, char sep);


void		ft_free(char **arr);
void		free_stack_a(t_list **node);
void		free_array(char **arr);

int			ft_lstadd_back(t_list **alst, t_list *news);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);

// handle error
int			ft_valid_num_check(const char *str);
int			ft_dup_check(int *numbers, int n);
int			ft_fill_stack(t_list **stack_a, char **arg);
int			ft_parssing(char *str);

//
void		ft_sort_numbers(t_list **stack_a, t_list **stack_b, int size);
int 		ft_swap_two_nums(t_list **stack_a, t_list **stack_b, int flag);

#endif