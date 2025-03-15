/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:54:31 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/15 07:57:58 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	*ft_parse_input(char *str, int *count_word)
{
	int		*nbrs;
	char	**split_str;
	int		j;
	long	atoi_result;

	*count_word = ft_len(str, ' ');
	nbrs = malloc(sizeof(int) * (*count_word));
	if (!nbrs)
		return (ft_putstr_fd("\033[1;31m🛑ERROR:\033allocation failed\n", 2), NULL);
	split_str = ft_split(str, ' ');
	if (!split_str)
		return (free(nbrs), ft_putstr_fd("\033🛑ERROR:\033failed\n", 2), NULL);
	j = 0;
	while (j < *count_word)
	{
		atoi_result = ft_atoi(split_str[j]);
		if (atoi_result == ((long)INT_MAX + 1))
		{
			ft_putstr_fd("\033[1;31m🛑ERROR: Integer overflow\033[0m\n", 2);
			return (free(nbrs), free_array(split_str), NULL);
		}
		nbrs[j] = (int)atoi_result;
		j++;
	}
	return (free_array(split_str), nbrs);
}

int	ft_parssing(char *str)
{
	int	count_word;
	int	*nbrs;

	nbrs = ft_parse_input(str, &count_word);
	if (!nbrs)
		return (0);
	if (!ft_dup_check(nbrs, count_word))
		return (free(nbrs), 0);
	free(nbrs);
	return (1);
}
