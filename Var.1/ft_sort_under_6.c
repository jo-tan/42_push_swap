/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_under_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:40 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:27:40 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_min_position(t_list **stack_a)
{
	t_list	*tmp;
	int		position;
	int		smallest_index;

	position = 1;
	smallest_index = ft_smallest_index(stack_a);
	tmp = *stack_a;
	while (tmp -> index != smallest_index)
	{
		position++;
		tmp = tmp -> next;
	}
	return (position);
}

void	ft_sort_3(t_list **stack_a)
{
	int	highest;

	if (ft_is_clean(stack_a))
		return ;
	highest = ft_highest_index(stack_a);
	if ((*stack_a)-> index == highest)
		ft_ra(stack_a);
	else if ((*stack_a)-> next -> index == highest)
		ft_rra(stack_a);
	if ((*stack_a)-> index > (*stack_a)-> next -> index)
		ft_sa(stack_a);
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (ft_is_clean(stack_a))
		return ;
	min = ft_min_position(stack_a);
	if (min == 2)
		ft_sa(stack_a);
	else if (min == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (min == 4)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_b, stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_position;

	min_position = ft_min_position(stack_a);
	if (ft_is_clean(stack_a))
		return ;
	if (min_position == 2)
		ft_sa(stack_a);
	else if (min_position == 3)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (min_position == 4)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (min_position == 5)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	ft_pa(stack_b, stack_a);
}

void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (ft_is_clean(stack_a) || ft_lst_size(*stack_a) == 0
		|| ft_lst_size(*stack_a) == 1)
		return ;
	size = ft_lst_size(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
}
