/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing_ascending.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:51:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/05 12:55:02 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_small_value(t_list *stack)
{
	int	small_val;

	small_val = INT_MAX;
	while (stack)
	{
		if (stack->content < small_val && stack->index == -1)
			small_val = stack->content;
		stack = stack->next;
	}
	return (small_val);
}

static void	ft_index_value(t_list **stack, int smalllest, int i)
{
	t_list	*cur;

	cur = *stack;
	while (cur)
	{
		if (cur->content == smalllest && cur->index == -1)
			cur->index = i;
		cur = cur->next;
	}
}

void	ft_indexing_ascending(t_list **stack)
{
	int		i;
	int		smallest_value;
	int		size;

	i = 0;
	size = ft_lstsize(*stack);
	while (i < size)
	{
		smallest_value = ft_find_small_value(*stack);
		ft_index_value(stack, smallest_value, i);
		i++;
	}
}
