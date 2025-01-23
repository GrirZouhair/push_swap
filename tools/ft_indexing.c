/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:12 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/23 17:34:46 by zogrir           ###   ########.fr       */
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
			return(node->content);
		node = node->next;				
	}
	return(0);
}
/*
#include<stdio.h>
int main()
{
	t_list *node1 = ft_lstnew(90);
	t_list *node2 = ft_lstnew(80);
	node1->next = node2;
	int cur = ft_find_small(node1);
	int pos = ft_find_small_pos(node1, cur);
	// while (cur)
	// {
	// 	printf("%d\n", cur->content);
	// 	cur = cur->next;
	// }
	printf("%d", pos);
}
*/