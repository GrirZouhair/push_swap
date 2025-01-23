/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:18:03 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/23 17:26:33 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include<stdio.h>
int	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list *drafts;
	if (!*stack_a)
		return(0);
	drafts = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	drafts->next = NULL;
	ft_lstadd_front(stack_b, drafts);
	return (1);
}



int ft_push_a(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_b, stack_a))
		return(ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Memory allocation failed\n", 2), 0);
	ft_putstr_fd("pa", 1);
	return (1);
}

int	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return(ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Memory allocation failed\n", 2), 0);
	ft_putstr_fd("pb", 1);
	return (1);
}
/*
void ft_print_list(t_list *stack)
{
    while (stack)
    {
        printf("%d -> ", (stack->content)); // Assuming content is an integer pointer
        stack = stack->next;
    }
    printf("NULL\n");
}

int main()
{
	t_list *stack_a = ft_lstnew(90);
	t_list *node2 = ft_lstnew(80);
	t_list *node3 = ft_lstnew(70);

	stack_a->next = node2;
	node2->next = node3;
	
	t_list *stack_b = NULL;

	printf("stack_a : \n");
	ft_print_list(stack_a);	
	printf("stack_b : \n");
	ft_print_list(stack_b);

	printf("\nPerforming pb (push from A to B):\n");
    ft_push_b(&stack_a, &stack_b);
    printf("Stack A: ");
    ft_print_list(stack_a);
    printf("Stack B: ");
    ft_print_list(stack_b);

    printf("\nPerforming pb (push from A to B):\n");
    ft_push_b(&stack_a, &stack_b);
    printf("Stack A: ");
    ft_print_list(stack_a);
    printf("Stack B: ");
    ft_print_list(stack_b);

    printf("\nPerforming pa (push from B to A):\n");
    ft_push_b(&stack_a, &stack_b);
    printf("Stack A: ");
    ft_print_list(stack_a);
    printf("Stack B: ");
    ft_print_list(stack_b);
}
*/