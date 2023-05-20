/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:18 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:36:27 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_reserve_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lst_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lst_last(*stack);
	while (head)
	{
		if (head -> next -> next == NULL)
		{
			head -> next = NULL;
			break ;
		}
		head = head -> next;
	}
	tail -> next = *stack;
	*stack = tail;
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_reserve_rotate(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_reserve_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rra(stack_a) == -1 || ft_rrb(stack_b) == -1)
		return (-1);
	ft_printf("rrr\n");
	return (0);
}
