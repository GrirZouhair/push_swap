/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:04:40 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:28:06 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_valid_num_check(const char *str)
{
	char	**splited;
	int		i;
	int		j;

	i = 0;
	splited = ft_split(str, ' ');
	if (!splited || !splited[0])
		return (free_array(splited), 0);
	while (splited[i])
	{
		j = 0;
		if (splited[i][0] == '+' || splited[i][0] == '-')
		{
			if (splited[i][1] == '+' || splited[i][1] == '-')
				return (free_array(splited), 0);
		}
		while (splited[i][j])
		{
			if (!(splited[i][j] >= '0' && splited[i][j] <= '9'))
				return (free_array(splited), 0);
			j++;
		}
		i++;
	}
	return (free_array(splited), 1);
}

static void	ft_fill(t_list **stack_a, char **splited)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (splited[i])
	{
		new_node = ft_lstnew_list(ft_atoi(*splited));
		if (!new_node)
		{
			free_stack_list(stack_a);
			free_array(splited);
			ft_putstr_fd("\033[1;31m🛑ERROR: Adding to list failed\033[0m\n", 2);
			exit(0);
		}
		ft_lstadd_back_list(stack_a, new_node);
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
			free_stack_list(stack_a);
			return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m\n", 2), 0);
		}
		ft_fill(stack_a, splited);
		free_array(splited);
		i++;
	}
	return (1);
}
