/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:05:22 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:26:45 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_stack_list(t_list **node)
{
	t_list	*tmp;

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

void	free_stack_opr(t_opr **node)
{
	t_opr	*tmp;

	if (!node || !*node)
		return ;
	while (*node)
	{
		tmp = ((*node)->next);
		free((*node)->ptr);
		free(*node);
		*node = tmp;
	}
	*node = NULL;
}

void	free_array(char **arr)
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
