/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:15:17 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 12:39:35 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_swap(t_list **stack)
{
	t_list	*draft;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	draft = *stack;
	*stack = (*stack)->next;
	draft->next = (*stack)->next;
	(*stack)->next = draft;
	return (0);
}

int	ft_swap_s(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 0)
	{
		if (!ft_swap(stack_a))
			return (1);
	}
	else if (flag == 1)
	{
		if (!ft_swap(stack_b))
			return (1);
	}
	else if (flag == 2)
	{
		if (!ft_swap(stack_a) || !ft_swap(stack_b))
			return (1);
	}
	return (0);
}
