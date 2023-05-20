/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:01:04 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:38:27 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*tmp_n1;
	t_list	*tmp_n2;

	if (*stack == NULL || (*stack)-> next == NULL)
		return (-1);
	tmp_n1 = *stack;
	tmp_n2 = (*stack)-> next;
	tmp_n1 -> next = tmp_n2 -> next;
	tmp_n2 -> next = tmp_n1;
	*stack = tmp_n2;
	return (0);
}

int	ft_sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_sa(stack_a) == -1 || ft_sb(stack_b) == -1)
		return (-1);
	ft_printf("ss\n");
	return (0);
}
