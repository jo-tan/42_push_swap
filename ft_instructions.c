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

int	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (*stack_from == NULL)
		return (-1);
	tmp = *stack_from;
	*stack_from = (*stack_from) -> next;
	tmp -> next = *stack_to;
	*stack_to = tmp;
	return (0);
}

int	ft_swap(t_list **stack)
{
	t_list	*tmp_n1;
	t_list	*tmp_n2;

	if (*stack == NULL || (*stack) -> next == NULL)
		return (-1);
	tmp_n1 = *stack;
	tmp_n2 = (*stack) -> next;

	tmp_n1 -> next = tmp_n2 -> next;
	tmp_n2 -> next = tmp_n1;

	*stack = tmp_n2;
	return (0);
}

int	ft_rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_second_to_last;
	t_list	*tmp_first;

	if (*stack == NULL || (*stack) -> next == NULL)
		return (-1);
	tmp_last = *stack;
	tmp_first = *stack;
	tmp_second_to_last = NULL;
	while (tmp_last -> next != NULL)
	{
		tmp_second_to_last = tmp_last;
		tmp_last = tmp_last -> next;
	}
	tmp_second_to_last -> next = tmp_first;
	*stack = tmp_last;
	tmp_last -> next = tmp_first -> next;
	tmp_first -> next = NULL;
	return (0);
}

int	ft_reserve_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lst_size(*stack) < 2)
		return (-1) ;
	head = *stack;
	tail = ft_lst_last(*stack);
	while (head)
	{
		if (head -> next -> next == NULL)
		{
			head -> next = NULL;
				break;
		}
		head = head -> next;
	}
	tail -> next = *stack;
	*stack = tail;
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

int	ft_sa(t_list **stack_a)
{
	if(ft_swap(stack_a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if(ft_swap(stack_b) == -1)
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