/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positioning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:28 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:32:32 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_small(t_list *node)
{
	int	small;

	small = INT_MAX;
	while (node)
	{
		if (small > node->content)
			small = node->content;
		node = node->next;
	}
	return (small);
}

void	ft_positioning(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		i++;
		stack = stack->next;
	}
}

int	ft_find_small_pos(t_list *node, int small)
{
	while (node)
	{
		if (node->content == small)
			return (node->position);
		node = node->next;
	}
	return (-1);
}
