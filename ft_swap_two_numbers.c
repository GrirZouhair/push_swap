/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_two_nums.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:58:00 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/21 13:21:08 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_swap(t_list **stack)
{
	t_list *draft;
	if (!stack || !*stack || !(*stack)->next)
		return (0);
	draft = *stack;
	*stack = (*stack)->next;
	draft->next = (*stack)->next;
	(*stack)->next = draft;
	return (1);
}

int ft_swap_two_nums(t_list **stack_a, t_list **stack_b, int flag)
{
	(void)stack_b;
	if (flag == 0)
	{
		if (!ft_swap(stack_a))
			return (0);
		ft_putstr_fd("sa", 1);
	}
	return (1);
}
/*
#include<stdio.h>

int main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(4);
	t_list *node2 = ft_lstnew(1);
	t_list *node3 = ft_lstnew(0);
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	
	printf("%d\n", ft_swap_two_nums(&head, NULL, 0));
	
	
	//t_list *cur = head;
	// while (cur)
	// {
	// 	printf("%d\n", cur->content);
	// 	cur = cur->next;
	// }
	
}
*/