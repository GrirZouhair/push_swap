/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:58:00 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/04 00:28:24 by zogrir           ###   ########.fr       */
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
