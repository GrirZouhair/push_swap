/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_num_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:07:18 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/09 12:58:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
