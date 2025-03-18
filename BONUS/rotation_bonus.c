/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:15:13 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/18 10:57:03 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_rotation(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back_list(stack_a, tmp);
	return (1);
}

int	ft_rotation_main(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 3)
	{
		if (!ft_rotation(stack_a))
			return (0);
	}
	else if (flag == 4)
	{
		if (!ft_rotation(stack_b))
			return (0);
	}
	else if (flag == 5)
	{
		if (!ft_rotation(stack_a) || !ft_rotation(stack_b))
			return (0);
	}
	return (1);
}

static int	ft_rotation_reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*cur;

	if (!*stack || !(*stack)->next)
		return (0);
	cur = *stack;
	tmp = ft_lstlast(*stack);
	if (!cur->next)
		return (0);
	while (cur->next->next)
		cur = cur->next;
	cur->next = NULL;
	ft_lstadd_front(stack, tmp);
	return (1);
}

int	ft_rotation_rev_main(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 6)
	{
		if (!ft_rotation_reverse(stack_a))
			return (0);
	}
	else if (flag == 7)
	{
		if (!ft_rotation_reverse(stack_b))
			return (0);
	}
	else if (flag == 8)
	{
		if (!ft_rotation_reverse(stack_a) || !ft_rotation_reverse(stack_b))
			return (0);
	}
	return (1);
}
