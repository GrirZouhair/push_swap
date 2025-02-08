/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:03 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/08 00:33:54 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill(t_list **stack_a, char **splited)
{
	int	i;
	t_list	*new_node;

	i = 0;
	while (splited[i])
	{
		new_node = ft_lstnew(ft_atoi(*splited));
		if (!new_node)
		{
			free_stack(stack_a);
			free_array(splited);
			ft_putstr_fd("\033[1;31m🛑ERROR: Adding to list failed\033[0m\n", 2);
			exit(0);
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}

int	ft_fill_stack(t_list **stack_a, char **arg)
{
	int		i;
	char	**splited;

	i = 1;
	while (arg[i])
	{
		splited = ft_split(arg[i], ' ');
		if (!splited)
		{
			free_stack(stack_a);
			return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m\n", 2), 0);
		}
		ft_fill(stack_a, splited);
		free_array(splited);
		i++;
	}
	return (1);
}
