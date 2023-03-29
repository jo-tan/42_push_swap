/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:00:57 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/28 17:18:45 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_lst_new(int *data)
{
	t_list	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new -> data = data;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!new)
		return ;
	if (!lst)
	{
		ptr = &new;
		return ;
	}
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}
