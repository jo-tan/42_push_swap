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
	// void		*dummy;
	/*If b_head -> data == NULL, keep getting segfault 11.
	Possible solution: write a specific struct for dummy head*/
	// dummy = malloc(sizeof(void *));
	// b_head = ft_lst_new(dummy);
	b_head = malloc(sizeof(t_list));
	b_head -> next =

	return (b_head);
}


void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a) -> next;
	tmp -> next = *stack_b;
	*stack_b = tmp;
}

void	ft_swap(t_list **stack_b)
{
	t_list	*tmp_n1;
	t_list	*tmp_n2;

	if (*stack_b == NULL || (*stack_b) -> next == NULL)
		return ;
	tmp_n1 = *stack_b;
	tmp_n2 = (*stack_b) -> next;

	tmp_n1 -> next = tmp_n2 -> next;
	tmp_n2 -> next = tmp_n1;

	*stack_b = tmp_n2;
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_second_to_last;
	t_list	*tmp_first;

	if (*stack == NULL || (*stack) -> next == NULL)
		return ;
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
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}