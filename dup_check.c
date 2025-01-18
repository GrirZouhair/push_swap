/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:54:31 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 10:00:08 by zogrir           ###   ########.fr       */
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
