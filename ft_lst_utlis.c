/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:00:57 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:42:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_lst_new(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> data = data;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}

t_list	*ft_lst_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*ptr;

	if (*stack)
	{
		ptr = ft_lst_last(*stack);
		ptr -> next = new;
	}
	else
	{
		*stack = new;
		(*stack)-> next = NULL;
	}
}

int	ft_lst_size(t_list *head)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = head;
	while (tmp)
	{
		size++;
		tmp = tmp -> next;
	}
	return (size);
}
