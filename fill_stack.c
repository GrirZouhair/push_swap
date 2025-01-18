/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:03 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/18 18:38:23 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<unistd.h>
int ft_fill_stack(t_list **stack_a, char **arg)
{
    int i;
    int j;
    char **splited;

    i = 1;
    while (arg[i])
    {
        splited = ft_split(arg[i], ' ');
        if (!splited)
        {
            free_stack_a(stack_a);
            write(2, "Error: Memory allocation failed\n", 33);
            return (1);
        }
        j = 0;
        while (splited[j])
        {
            if (!ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(splited[j]))))
            {
                free_stack_a(stack_a);
                free_array(splited);
                write(2, "Error: Adding to list failed\n", 29);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        free_array(splited);
        i++;
    }
    return (0);
}

/*
#include<stdio.h>
int main()
{
    t_list *node = NULL;
    char *array[] = {"./program", "42 3 12", NULL};

    if (ft_fill_stack(&node, array) != 0)
    {
        printf("Error occurred while filling stack\n");
        return (1);
    }

    // Example of accessing the list
    t_list *current = node;
    while (current)
    {
        printf("%d\n", current->content);
        current = current->next;
    }

    free_stack_a(&node);
    return (0);
}

*/