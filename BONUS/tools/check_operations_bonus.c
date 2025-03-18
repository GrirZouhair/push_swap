/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:14:59 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:26:03 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	s1(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (!ft_cmp(operation, "sa\n"))
		ft_swap_s(stack_a, stack_b, SA);
	else if (!ft_cmp(operation, "sb\n"))
		ft_swap_s(stack_a, stack_b, SB);
	else if (!ft_cmp(operation, "ss\n"))
		ft_swap_s(stack_a, stack_b, SS);
	else if (!ft_cmp(operation, "ra\n"))
		ft_rotation_main(stack_a, stack_b, RA);
	else if (!ft_cmp(operation, "rb\n"))
		ft_rotation_main(stack_a, stack_b, RB);
	else if (!ft_cmp(operation, "rr\n"))
		ft_rotation_main(stack_a, stack_b, RR);
	else if (!ft_cmp(operation, "rra\n"))
		ft_rotation_rev_main(stack_a, stack_b, RRA);
	else if (!ft_cmp(operation, "rrb\n"))
		ft_rotation_rev_main(stack_a, stack_b, RRB);
	else if (!ft_cmp(operation, "rrr\n"))
		ft_rotation_rev_main(stack_a, stack_b, RRR);
	else if (!ft_cmp(operation, "pa\n"))
		ft_push_a(stack_a, stack_b);
	else if (!ft_cmp(operation, "pb\n"))
		ft_push_b(stack_a, stack_b);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, t_opr **opr)
{
	t_opr	*temp;

	temp = *opr;
	while (temp)
	{
		s1(temp->ptr, stack_a, stack_b);
		temp = temp->next;
	}
}

static int	ft_is_same(char *line)
{
	if (!ft_cmp(line, "sa\n") || !ft_cmp(line, "sb\n")
		|| !ft_cmp(line, "ss\n") || !ft_cmp(line, "ra\n")
		|| !ft_cmp(line, "rb\n") || !ft_cmp(line, "rr\n")
		|| !ft_cmp(line, "rra\n") || !ft_cmp(line, "rrb\n")
		|| !ft_cmp(line, "rrr\n") || !ft_cmp(line, "pa\n")
		|| !ft_cmp(line, "pb\n"))
	{
		return (1);
	}
	return (0);
}

int	ft_check_operations(t_opr **opr)
{
	char	*line;
	t_opr	*new_node;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		if (ft_is_same(line))
		{
			new_node = ft_lstnew_opr(line);
			if (!new_node)
				return (free_stack_opr(&new_node), 0);
			ft_lstadd_back_opr(opr, new_node);
		}
		else
		{
			free_stack_opr(opr);
			free(line);
			return (0);
		}
	}
	return (1);
}
