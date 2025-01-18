/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 12:18:51 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	
	// fill stack 'a' with numbers from command line arg

	// decide which sorting algo
	int stack_size = ft_lstsize(a);
	if (stack_size <= 3)
	{
		handle_small_stack(&a);
	}
	else if (stack_size <= 5)
	{
		handle_small_stack(&a);
	}
	else if (stack_size <= 100)
	{
		handle_medium_stack(&a);
	}
	else
	{
		handle_large_stack(&a);
	}
	//ft_lstclear(&a, free);
}