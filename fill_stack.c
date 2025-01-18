/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:03 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 13:26:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_fill_stack(t_list **stack_a, char **arg)
{
	int	i;
	int	j;
	char **splited;

	i = 1; // iterate at av
	j = 0;
	while (arg[i])
	{
		splited = ft_split(arg[i], ' ');
		if (!arg)
			return (NULL);
		j = 0;
		while (splited[j])
		{
			if (!ft_lstadd_back(stack_a, ft_atoi(splited[j])))
			{
				
			}
			j++;
		}
		i++;
	}
	
	
}