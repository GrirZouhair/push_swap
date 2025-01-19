/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:54:31 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/19 15:47:35 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *pt1, int *pt2)
{
	int	tmp;
	tmp = *pt1;
	*pt1 = *pt2;
	*pt2 = tmp;
}

int ft_dup_check(int *numbers, int n)
{
	int	i;
	int j;
	int swapped;
	
	i = 0;
	
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n -i -1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap(&numbers[j], &numbers[j + 1]);
				swapped = 1;
			}
			j++;
		}
		i++;
		if (swapped == 0)
			break;
	}
	i = 0;
	while (i < n - 1)
	{
		if (numbers[i] == numbers[i + 1])
			return (0);
		i++;
	}
	
	return(1);
}

int ft_parssing(char *str)
{
    int count_word;
    int *nbrs;
    char **split_str;
    int j;

    if (!str)
        return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Invalid input string\n", 2), 0);
    count_word = ft_len(str, ' ');
    if (count_word <= 0)
        return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Empty or invalid string\n", 2), 0);
    nbrs = malloc(sizeof(int) * count_word);
    if (!nbrs)
        return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Memory allocation failed\n", 2), 0);
    split_str = ft_split(str, ' ');
    if (!split_str)
        return (free(nbrs), ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m Split failed\n", 2), 0);

    j = 0;
    while (j < count_word)
    {
        nbrs[j] = ft_atoi(split_str[j]);
        j++;
    }
    if (!ft_dup_check(nbrs, count_word))
        return (ft_free(split_str), free(nbrs), 0);
    
    ft_free(split_str);
    free(nbrs);
    return (1);
}
