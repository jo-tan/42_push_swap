/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utlis_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:04 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 19:13:01 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lst_delete(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head -> next;
		free(tmp);
	}
	free(stack);
}

void	ft_print_nodes(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("node: %i, index: %i\n", tmp -> data, tmp -> index);
		tmp = tmp -> next;
	}
}

void	ft_free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lst_delete(stack_a);
	ft_lst_delete(stack_b);
}

void	ft_error(t_list **stack)
{
	ft_lst_delete(stack);
	ft_printf("ERROR\n");
}
