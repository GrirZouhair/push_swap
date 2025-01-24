/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:50:58 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/24 09:17:11 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"



void ft_sort_numbers(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*cur;
	if (size == 2)
	{
		ft_swap_s(stack_a, NULL, SA);
	}
	else if (size == 3)
	{
		cur = *stack_a;
		if (cur->content > cur->next->content &&
			cur->content > cur->next->next->content)
			ft_rotation_main(stack_a, NULL, RA);
		else if (cur->next->content > cur->content &&
			cur->next->content > cur->next->next->content)
			ft_rotation_reverse_main(stack_a, NULL, RRA);
		cur = *stack_a;
		if(cur->content > cur->next->content)
			ft_swap_s(stack_a, NULL, SA);
	}
	else if (size == 4)
	{
		ft_swap_four(stack_a, stack_b);
	}
	else if (size == 5)
	{
		ft_swap_five(stack_a, stack_b);	
	}
	else{
		write(1, "more than 5 numbers", 20);
	}
}