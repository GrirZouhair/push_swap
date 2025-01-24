/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/24 11:24:40 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
typedef struct s_list
{
	int		content;
	int		position;
	struct	s_list *next;
} t_list;

#define SA 0
#define SB 1
#define SS 2
#define RA 3
#define RB 4
#define RR 5
#define RRA 6
#define RRb 7
#define RRR 8
// utils
char		**ft_split(char const *s, char c);
int			ft_len(const char *s, char c);
int			ft_atoi(const char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(int size, char **strs, char sep);
void		ft_indexing(t_list *stack);
int			ft_find_small(t_list *node);
int			ft_find_small_pos(t_list *node, int small);
int			ft_find_small(t_list *node);
void		ft_indexing(t_list *stack);



void		ft_free(char **arr);
void		free_stack_a(t_list **node);
void		free_array(char **arr);

int			ft_lstadd_back(t_list **alst, t_list *news);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);

// handle error
int			ft_valid_num_check(const char *str);
int			ft_dup_check(int *numbers, int n);
int			ft_fill_stack(t_list **stack_a, char **arg);
int			ft_parssing(char *str);

//
void		ft_sort_numbers(t_list **stack_a, t_list **stack_b, int size);
int 		ft_swap_s(t_list **stack_a, t_list **stack_b, int flag);
int			ft_rotation_main(t_list **stack_a, t_list **stack_b, int flag);
int			ft_rotation_reverse_main(t_list **stack, t_list **stack_b, int flag);
void		ft_swap_four(t_list **stack_a, t_list **stack_b);
int			ft_push_a(t_list **stack_a, t_list **stack_b);
int			ft_push_b(t_list **stack_a, t_list **stack_b);
void		ft_swap_five(t_list **stack_a, t_list **stack_b);

#endif