/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:23:53 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/24 11:24:14 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;
	
	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->position   = -1;
	ptr->next    = NULL;
	return (ptr);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return(lst);
}

int		ft_lstsize(t_list *lst)
{
	int		i;
	if (!lst)	
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lstadd_back(t_list **alst, t_list *news)
{
	t_list	*last;
	if (!news)
		return (0);
	if (!alst)
		return (0);
	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = news;
	}
	else
	{
		*alst = news;
	}
	return (1);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		*lst = new;
	}
}

/*
#include<stdio.h>
int main()
{
	int n1 = 1; 
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	t_list *node1 = ft_lstnew(n1);
	t_list *node2 = ft_lstnew(n2);
	t_list *node3 = ft_lstnew(n3);
	t_list *node4 = ft_lstnew(n4);

	
	t_list *head = NULL;
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node4);

	
	t_list *current = head;
	
	while (current)
	{
		printf("content  : %d\n", (int)current->content);
		current = current->next;
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
}
*/