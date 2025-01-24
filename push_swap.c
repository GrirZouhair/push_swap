/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/24 11:33:04 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		size;
	char *str;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_valid_num_check(av[i]))
			return (ft_putstr_fd("\033[1;31m🛑ERROR 1:\033[0m\n", 2), 0);
		i++;
	}
	str = ft_strjoin(ac - 1, av + 1, ' '); // we need to merge them in a signle array to check for all arguments
	if (!str || ft_fill_stack(&stack_a, av) == -1 || !ft_parssing(str))
		return (ft_putstr_fd("\033[1;31m🛑ERROR 2: \033[0m\n", 2), 0);
	size = ft_lstsize(stack_a);
	
	ft_sort_numbers(&stack_a, &stack_b, size);
}	
	
	
// 	if (ft_is_sorted())
// 		ft_sorted(&stack_a, &stack_b, size);
// }


	//int stack_size = ft_lstsize();
	// if (stack_size <= 3)
	// {
	// 	//handle_small_stack();
	// }
	// else if (stack_size <= 5)
	// {
	// 	//handle_small_stack();
	// }
	// else if (stack_size <= 100)
	// {
	// 	//handle_medium_stack();
	// }
	// else
	// {
	// 	//handle_large_stack();
	// }
	//ft_lstclear(, free);