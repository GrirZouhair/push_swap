/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:16:36 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/18 10:56:42 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				position;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_opr
{
	char			*ptr;
	struct s_opr	*next;
}	t_opr;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define SA 0
# define SB 1
# define SS 2
# define RA 3
# define RB 4
# define RR 5
# define RRA 6
# define RRB 7
# define RRR 8
# define PV1 16
# define PV2 32

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strdup(const char *s);
int		ft_len(const char *s, char c);
char	**ft_split(char const *s, char c);
void	free_stack_list(t_list **node);
void	free_stack_opr(t_opr **node);
void	free_array(char **arr);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_check_operations(t_opr **opr);
char	*get_next_line(int fd);
void	ft_lstadd_back_opr(t_opr **alst, t_opr *news);
void	ft_lstadd_back_list(t_list **alst, t_list *news);
int		ft_lstsize(t_list *lst);

int		ft_rotation_main(t_list **stack_a, t_list **stack_b, int flag);
int		ft_rotation_rev_main(t_list **stack_a, t_list **stack_b, int flag);
int		sorted(t_list *stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_opr **opr);
char	*ft_join(int size, char **strs);
int		ft_valid_num_check(const char *str);
t_opr	*ft_lstnew_opr(char *content);
t_list	*ft_lstnew_list(int content);
int		ft_fill_stack(t_list **stack_a, char **arg);
int		ft_parssing(char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_swap_s(t_list **stack_a, t_list **stack_b, int flag);
int		ft_push_a(t_list **stack_a, t_list **stack_b);
int		ft_push_b(t_list **stack_a, t_list **stack_b);
#endif