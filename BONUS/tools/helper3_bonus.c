/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:13:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/10 15:30:23 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_lstadd_back_list(t_list **alst, t_list *news)
{
	t_list	*last;

	if (alst != NULL && news)
	{
		last = *alst;
		if (last == NULL)
		{
			*alst = news;
		}
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = news;
		}
		news->next = NULL;
	}
}

void	ft_lstadd_back_opr(t_opr **alst, t_opr *news)
{
	t_opr	*last;

	if (alst != NULL && news)
	{
		last = *alst;
		if (last == NULL)
		{
			*alst = news;
		}
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = news;
		}
		news->next = NULL;
	}
}

t_list	*ft_lstnew_list(int content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->position = -1;
	ptr->index = -1;
	ptr->next = NULL;
	return (ptr);
}

t_opr	*ft_lstnew_opr(char *content)
{
	t_opr	*cur;

	cur = (t_opr *)malloc(sizeof(t_opr));
	if (!cur)
		return (NULL);
	cur->ptr = content;
	cur->next = NULL;
	return (cur);
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
