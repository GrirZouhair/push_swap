/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:02:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:27:34 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	sorted(t_list *stack_a)
{
	t_list	*cur;

	cur = stack_a;
	while (cur->next)
	{
		if (cur->content > cur->next->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}
