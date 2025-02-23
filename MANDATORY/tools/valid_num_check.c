/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_num_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:07:18 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/22 19:59:57 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_valid_number(const char *num)
{
	int	j;

	j = 0;
	if (num[j] == '+' || num[j] == '-')
	{
		if (num[j + 1] == '+' || num[j + 1] == '-')
			return (0);
		j++;
	}
	while (num[j])
	{
		if (!(num[j] >= '0' && num[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}

int	ft_valid_num_check(const char *str)
{
	char	**splited;
	int		i;

	splited = ft_split(str, ' ');
	if (!splited || !splited[0])
		return (free_array(splited), 0);
	i = 0;
	while (splited[i])
	{
		if (!ft_is_valid_number(splited[i]))
			return (free_array(splited), 0);
		i++;
	}
	return (free_array(splited), 1);
}

