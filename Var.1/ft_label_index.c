/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:09:46 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:51:03 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_find_min(t_list **stack_a)
{
	t_list	*head;
	t_list	*runner;
	t_list	*min;
	int		find_min;

	head = *stack_a;
	runner = head;
	min = head;
	find_min = 0;
	while (runner)
	{
		if ((runner -> index == -1)
			&& (!find_min || runner -> data < min -> data))
		{
			min = runner;
			find_min = 1;
		}
		runner = runner -> next;
	}
	return (min);
}

static int	ft_not_label(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	while (head)
	{
		if (head -> index == -1)
			return (1);
		head = head -> next;
	}
	return (0);
}

void	ft_label_index(t_list **stack_a)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = ft_find_min(stack_a);
	while (ft_not_label(stack_a) == 1)
	{
		tmp -> index = index++;
		tmp = ft_find_min(stack_a);
	}
}

int	ft_highest_index(t_list **stack_a)
{
	t_list	*tmp;
	int		highest;

	tmp = *stack_a;
	highest = tmp -> index;
	while (tmp)
	{
		if (tmp -> index > highest)
			highest = tmp -> index;
		tmp = tmp -> next;
	}
	return (highest);
}

int	ft_smallest_index(t_list **stack_a)
{
	t_list	*tmp;
	int		smallest;

	tmp = *stack_a;
	smallest = tmp -> index;
	while (tmp)
	{
		if (tmp -> index < smallest)
			smallest = tmp -> index;
		tmp = tmp -> next;
	}
	return (smallest);
}
