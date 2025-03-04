/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:50:58 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/05 16:43:05 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*draft;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	draft = *stack;
	*stack = (*stack)->next;
	draft->next = (*stack)->next;
	(*stack)->next = draft;
	return (1);
}

int	ft_swap_s(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 0)
	{
		if (!ft_swap(stack_a))
			return (0);
		ft_putstr_fd("sa", 1);
	}
	else if (flag == 1)
	{
		if (!ft_swap(stack_b))
			return (0);
		ft_putstr_fd("sb", 1);
	}
	else if (flag == 2)
	{
		if (!ft_swap(stack_a) || !ft_swap(stack_b))
			return (0);
		ft_putstr_fd("ss", 1);
	}
	return (1);
}

void	ft_sorting_algo(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*cur;

	if (size == 2)
		ft_swap_s(stack_a, NULL, SA);
	else if (size == 3)
	{
		cur = *stack_a;
		if (cur->content > cur->next->content
			&& cur->content > cur->next->next->content)
			ft_rotation_main(stack_a, NULL, RA);
		else if (cur->next->content > cur->content
			&& cur->next->content > cur->next->next->content)
			ft_rotation_rev_main(stack_a, NULL, RRA);
		cur = *stack_a;
		if (cur->content > cur->next->content)
			ft_swap_s(stack_a, NULL, SA);
	}
	else if (size == 4)
		ft_swap_four(stack_a, stack_b);
	else if (size == 5)
		ft_swap_five(stack_a, stack_b);
	else
		ft_sort_long_num(stack_a, stack_b);
}
