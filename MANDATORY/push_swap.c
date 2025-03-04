/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 14:53:10 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_parse_input(int ac, char **av)
{
	int		i;
	char	*arr;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_valid_num_check(av[i]))
		{
			ft_putstr_fd("\033[1;31m🛑ERROR 1:\033[0m\n", 2);
			return (0);
		}
		i++;
	}
	arr = ft_join(ac - 1, av + 1);
	if (!arr || !ft_parssing(arr))
	{
		ft_putstr_fd("\033[1;31m🛑ERROR 2:\033[0m\n", 2);
		free(arr);
	}
	free(arr);
	return (1);
}

static void	ft_sort_algo(char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_fill_stack(&stack_a, av))
	{
		free_stack(&stack_a);
		ft_putstr_fd("\033[1;31m🛑ERROR 3:\033[0m\n", 2);
		return ;
	}
	size = ft_lstsize(stack_a);
	ft_indexing(&stack_a);
	if (!sorted(stack_a))
		ft_sorting_algo(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int ac, char **av)
{
	if (!validate_and_parse_input(ac, av))
		return (0);
	ft_sort_algo(av);
}
