/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_num_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:07:18 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/19 09:26:47 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_valid_num_check(const char *str)
{
	char	**splited;
	int		i;
	int		j;

	i = 0;
	splited = ft_split(str, ' ');
	
	if (!splited || !splited[0])
		return (ft_free(splited), 0);
	while (splited[i])
	{
		j = 0;
		if(splited[i][0] == '+' || splited[i][0] == '-')
		{
			if (splited[i][1] == '+' || splited[i][1] == '-')
				return (ft_free(splited), 0);
		}
		while (splited[i][j])
		{
			if (!(splited[i][j] >= '0' && splited[i][j] <= '9'))
			{
				return (ft_free(splited), 0);
			}
			j++;
		}
		i++;
	}
	
	return (ft_free(splited), 1);
}
// #include<stdio.h>
// int main()
// {
// 	char s[] = "12 1 4l";
// 	printf("%d", ft_valid_num_check(s));
// }