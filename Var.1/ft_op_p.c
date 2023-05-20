/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:58:34 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:43:04 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (*stack_from == NULL)
		return (-1);
	tmp = *stack_from;
	*stack_from = (*stack_from)-> next;
	tmp -> next = *stack_to;
	*stack_to = tmp;
	return (0);
}

int	ft_pa(t_list **stack_b, t_list **stack_a)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
