/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:22:00 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/22 11:20:11 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotation(t_list **stack_a)
{
	t_list *tmp;
	
	if (!stack_a)
		return (0);
	
	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	return (1);
}

int	ft_rotation_main(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 3)
	{
		if (!ft_rotation(stack_a))
			return (0);
		ft_putstr_fd("ra", 1);		
	}
	else if (flag == 4)
	{
		if (!ft_rotation(stack_b))
			return (0);
		ft_putstr_fd("rb", 1);
	}
	else if (flag == 5)
	{
		if (!ft_rotation(stack_a) || !ft_rotation(stack_b))
			return (0);
		ft_putstr_fd("rr", 1);
	}
	return (1);
}


int	ft_rotation_reverse(t_list **stack)
{
	t_list 	*tmp;
	t_list  *cur;

	cur = (*stack);
	tmp = ft_lstlast(*stack);
	while (cur->next->next)
		cur = cur->next;
	cur->next = NULL;
	ft_lstadd_front(stack, tmp);
	return (1);
}

int	ft_rotation_reverse_main(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 6)
	{
		if (!ft_rotation_reverse(stack_a))
			return (0);
		ft_putstr_fd("rra", 1);
	}
	else if (flag == 7)
	{
		if (!ft_rotation_reverse(stack_b))
			return (0);
		ft_putstr_fd("rrb", 1);	
	}
	else if (flag == 8)
	{
		if (!ft_rotation_reverse(stack_a) || !ft_rotation_reverse(stack_b))
			return (0);
		ft_putstr_fd("rrr", 1);
	}
	return (1);
}



// #include<stdio.h>
// int main()
// {
// 	t_list *node1 = ft_lstnew(3);
// 	t_list *node2 = ft_lstnew(1);
// 	t_list *node3 = ft_lstnew(2);

// 	node1->next = node2;
// 	node2->next = node3;
	
// 	ft_rotation_reverse_main(&node1, NULL, 6);
// 	printf("\n");
// 	t_list *cur = node1;
	
// 	while (cur)
// 	{
// 		printf("%d\n", cur->content);
// 		cur = cur->next;
// 	}
	
// }