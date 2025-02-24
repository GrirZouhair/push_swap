/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 14:25:42 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		size;
	char	*str;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_valid_num_check(av[i]))
		{
			return (ft_putstr_fd("\033[1;31m🛑ERROR 1:\033[0m\n", 2), 0);
			exit(0);
		}
		i++;
	}
	str = ft_join(ac - 1, av + 1);
	if (!str || !ft_fill_stack(&stack_a, av) || !ft_parssing(str))
		return (ft_putstr_fd("\033[1;31m🛑ERROR 2: \033[0m\n", 2), 0);
	size = ft_lstsize(stack_a);
	ft_indexing(&stack_a);
	if (!sorted(stack_a))
		ft_sorting_algo(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
