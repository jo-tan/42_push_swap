/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:13:41 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:53:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		bit_position;
	int		j;
	int		max_bits;
	int		size;

	size = ft_lst_size(*stack_a);
	max_bits = 0;
	bit_position = -1;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	while (++bit_position < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			head = *stack_a;
			if (((head -> index >> bit_position) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (*stack_b)
			ft_pa(stack_b, stack_a);
	}
}
