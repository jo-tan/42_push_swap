/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:02:35 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:34:24 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_first;

	if (*stack == NULL || (*stack)-> next == NULL)
		return (-1);
	tmp_last = *stack;
	*stack = (*stack)-> next;
	tmp_first = *stack;
	while (tmp_first -> next != NULL)
		tmp_first = tmp_first -> next;
	tmp_first -> next = tmp_last;
	tmp_last -> next = NULL;
	return (0);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int	ft_rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a) == -1 || ft_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rr\n");
	return (0);
}
