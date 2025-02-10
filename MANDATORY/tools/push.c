/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:18:03 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:33:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*drafts;

	if (!*stack_a)
		return (0);
	drafts = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	drafts->next = NULL;
	ft_lstadd_front(stack_b, drafts);
	return (1);
}

int	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_b, stack_a))
		return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m failed\n", 2), 0);
	ft_putstr_fd("pa", 1);
	return (1);
}

int	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m failed\n", 2), 0);
	ft_putstr_fd("pb", 1);
	return (1);
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
