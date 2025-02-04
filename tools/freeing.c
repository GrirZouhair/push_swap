/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:05:22 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 17:32:47 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack_a(t_list **node)
{
	t_list *tmp;

	if (!node || !*node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;		
	}
	*node = NULL;
}
void	free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);	
}