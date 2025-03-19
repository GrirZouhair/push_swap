/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:29:15 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/19 02:18:37 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
		return (0);
	return (1);
}

int	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (0);
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
