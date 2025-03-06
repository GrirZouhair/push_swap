/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:28:49 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/06 13:21:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_ft(t_list *stack_a, t_list *stack_b, t_opr *opr)
{
	sort_stack(&stack_a, &stack_b, &opr);
	if (sorted(stack_a) == 1 && ft_lstsize(stack_b) == 0)
		return (free_stack_list(&stack_a), free_stack_opr(&opr),
			ft_putstr_fd("OK", 1), 1);
	return (free_stack_list(&stack_a), free_stack_list(&stack_b),
		free_stack_opr(&opr), ft_putstr_fd("KO", 2), 1);
}

static int	ft_validate(int ac, char **av, t_list **stack_a, t_opr **opr)
{
	int		i;
	char	*str;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_valid_num_check(av[i]))
			return (ft_putstr_fd("Error", 2), 0);
		i++;
	}
	str = ft_join(ac - 1, av + 1);
	if (!str || !ft_fill_stack(stack_a, av) || !ft_parssing(str))
		return (free(str), ft_putstr_fd("Error", 2), 0);
	free(str);
	if (!ft_check_operations(opr))
		return (free_stack_list(stack_a),
			free_stack_opr(opr), ft_putstr_fd("Error", 2), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_opr	*opr;

	stack_b = NULL;
	stack_a = NULL;
	opr = NULL;
	if (!ft_validate(ac, av, &stack_a, &opr))
		return (0);
	ft_ft(stack_a, stack_b, opr);
}
