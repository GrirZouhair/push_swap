/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:12 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/24 11:29:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	ft_find_small(t_list *node)
{
	int	small;
	small = INT_MAX;
	while (node)
	{
		if (small > node->content)
			small = node->content;
		node = node->next;
	}
	return (small);
}


void	ft_indexing(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		i++;
		stack = stack->next;
	}
}
int	ft_find_small_pos(t_list *node, int small)
{
	while (node)
	{
		if (node->content == small)
			return(node->position);
		node = node->next;				
	}
	return(-1);
}

// #include<stdio.h>
// int main()
// {
// 	t_list *node1 = ft_lstnew(90);
// 	t_list *node2 = ft_lstnew(80);
// 	t_list *node3 = ft_lstnew(70);
// 	t_list *node4 = ft_lstnew(60);
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;
// 	ft_indexing(node1);
// 	// int cur = ft_find_small(node1);
// 	// int pos = ft_find_small_pos(node1, cur);
// 	t_list *head = node1;
// 	while (head)
// 	{
// 		printf("%d\n", head->position);
// 		head = head->next;
// 	}
// 	// printf("%d\n", cur);
// 	// printf("%d\n", pos);
// }
