/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:19:25 by jo-tan            #+#    #+#             */
/*   Updated: 2023/04/17 08:32:34 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_create_lst_b(void)
{
	t_list	*b_head;

	b_head = malloc(sizeof(t_list));
	b_head -> data = NULL;

	return (b_head);
}


void	ft_pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_a;
	stack_a = stack_a -> next;
	tmp -> next = NULL;
	if (stack_b -> data == NULL)
	{
		stack_b -> next = tmp;
		stack_b = stack_b -> next;
	}
	else
	{
		tmp -> next = stack_b;
	}
}