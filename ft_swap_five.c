/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:08:42 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/05 16:43:14 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_five(t_list **stack_a, t_list **stack_b)
{
	int		small;
	int		pos;
	t_list	*tmp;

	tmp = *stack_a;
	ft_indexing(*stack_a);
	small = ft_find_small(tmp);
	pos = ft_find_small_pos(*stack_a, small);
	while ((*stack_a)->content != small)
	{
		if (pos < 2)
			ft_rotation_main(stack_a, stack_b, RA);
		else if (pos >= 2)
			ft_rotation_rev_main(stack_a, stack_b, RRA);
	}
	ft_push_b(stack_a, stack_b);
	ft_swap_four(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}
