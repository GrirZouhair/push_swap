/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:54:31 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/09 14:57:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	swap_num(int *pt1, int *pt2)
{
	int	tmp;

	tmp = *pt1;
	*pt1 = *pt2;
	*pt2 = tmp;
}

static int	ft_result(int *numbers, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (numbers[i] == numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_dup_check(int *numbers, int n)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i++ < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j++ < n - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap_num(&numbers[j], &numbers[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break ;
	}
	return (ft_result(numbers, n));
}

int	ft_parssing(char *str)
{
	int		count_word;
	int		*nbrs;
	char	**split_str;
	int		j;

	count_word = ft_len(str, ' ');
	if (count_word <= 0)
		return (ft_putstr_fd("Error", 2), 0);
	nbrs = malloc(sizeof(int) * count_word);
	if (!nbrs)
		return (ft_putstr_fd("Error", 2), 0);
	split_str = ft_split(str, ' ');
	if (!split_str)
		return (free(nbrs), ft_putstr_fd("Error", 2), 0);
	j = 0;
	while (j < count_word)
	{
		nbrs[j] = ft_atoi(split_str[j]);
		j++;
	}
	if (!ft_dup_check(nbrs, count_word))
		return (free_array(split_str), free(nbrs), 0);
	free_array(split_str);
	free(nbrs);
	return (1);
}
