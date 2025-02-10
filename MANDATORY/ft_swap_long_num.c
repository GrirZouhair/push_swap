/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_long_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:46 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/09 12:45:36 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_list	*head)
{
	int		bigesst;

	bigesst = INT_MIN;
	while (head)
	{
		if (head->content > bigesst)
			bigesst = head->content;
		head = head->next;
	}
	return (bigesst);
}

static void	ft_sendback(t_list **stack_a, t_list **stack_b)
{
	int	biggest;
	int	pos;
	int	size;

	while (*stack_b)
	{
		ft_positioning(*stack_b);
		biggest = find_biggest(*stack_b);
		pos = ft_find_small_pos(*stack_b, biggest);
		size = ft_lstsize(*stack_b);
		if (pos <= size / 2)
		{
			while ((*stack_b)->content != biggest)
				ft_rotation_main(NULL, stack_b, RB);
		}
		else
		{
			while ((*stack_b)->content != biggest)
				ft_rotation_rev_main(NULL, stack_b, RRB);
		}
		ft_push_a(stack_a, stack_b);
	}
}

static void	send_to_b(t_list **stack_a, t_list **stack_b, int pv)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_push_b(stack_a, stack_b);
			ft_rotation_main(NULL, stack_b, RB);
			i++;
		}
		else if ((*stack_a)->index <= i + pv)
		{
			ft_push_b(stack_a, stack_b);
			i++;
		}
		else
		{
			ft_rotation_rev_main(stack_a, NULL, RRA);
		}
	}
}

void	ft_sort_long_num(t_list **stack_a, t_list **stack_b)
{
	int	pv;
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 100)
		pv = PV1;
	else
		pv = PV2;
	send_to_b(stack_a, stack_b, pv);
	ft_sendback(stack_a, stack_b);
}
