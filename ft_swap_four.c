/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:29:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/23 18:59:38 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_four(t_list **stack_a, t_list **stack_b)
{
	int		small;
	int		pos;
	
	ft_indexing(*stack_a);
	small = ft_find_small(*stack_a);	
	pos = ft_find_small_pos(*stack_a, small);
	while ((*stack_a)->content != small)
	{
		if (pos < 2)
			ft_rotation_main(stack_a, stack_b, RA);
		else if (pos >= 2)
			ft_rotation_reverse_main(stack_a, stack_b, RRA);
	}
	ft_push_b(stack_a, stack_b);
	ft_sort_numbers(stack_a, stack_b, 3);
	ft_push_a(stack_a, stack_b);
}