/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:50:58 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/21 13:33:43 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void ft_sort_numbers(t_list **stack_a, t_list **stack_b, int size)
{
	(void)stack_b;
	if (size == 2)
	{
		ft_swap_two_nums(stack_a, NULL, SA);
	}
}