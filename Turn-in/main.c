/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:26:43 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 21:17:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_duplicate(t_list **stack_a)
{
	t_list	*current;
	t_list	*runner;

	current = *stack_a;
	while (current != NULL)
	{
		runner = current -> next;
		while (runner != NULL)
		{
			if (runner -> data == current -> data)
			{
				ft_error(stack_a);
				return (1);
			}
			runner = runner -> next;
		}
		current = current -> next;
	}
	return (0);
}

int	ft_initial_stack_a(int ac, char **av, t_list **stack_a)
{
	int			i;
	long int	nbr;
	t_list		*new;

	i = 1;
	while (i < ac)
	{
		if (ft_is_valid_nb(av[i]))
		{
			nbr = ft_atoi(av[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
				return (ft_error(stack_a), 0);
			new = ft_lst_new((int)nbr);
			ft_lstadd_back(stack_a, new);
		}
		else if (ft_valid_arg(av[i]) == 1)
			ft_parse_arg(stack_a, av[i]);
		else
			return (ft_error(stack_a), 0);
		i++;
	}
	if (ft_check_duplicate(stack_a))
		return (0);
	ft_label_index(stack_a);
	return (1);
}

int	ft_is_clean(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp -> next)
	{
		if (tmp -> data > tmp -> next -> data)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lst_size(*stack_a) < 6)
		ft_simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac == 1)
		return (0);
	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	if (ft_initial_stack_a(ac, av, stack_a) == 0)
		return (ft_lst_delete(stack_b), 0);
	if (ft_is_clean(stack_a))
	{
		ft_free_stacks(stack_a, stack_b);
		return (0);
	}
	ft_sort(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
