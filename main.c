/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:26:43 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/28 17:30:16 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*Save the arguments as int with ft_atoi(*s) and make a list
		use atoi to check the coentent, 
		if char is not between '0' - '9'; clear the content, free nodes and return error
		else; create new node
 * In case malloc failed in the middle, clear and free the lst and return an error msg*/

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
				ft_lst_delete(stack_a);
				ft_printf("EROOR\n");
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
	int	i;
	long int	nbr;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		if (ft_is_valid_nb(av[i]))
		{
			nbr = ft_atoi(av[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
			{
				ft_lst_delete(stack_a);
				return (ft_printf("ERROR\n"), 0);
			}
			new = ft_lst_new((int)nbr);
			ft_lstadd_back(stack_a, new);
		}
		else
		{
			ft_lst_delete(stack_a);
			return (ft_printf("ERROR\n"), 0);
		}
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

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ft_initial_stack_a(ac, av, stack_a) == 0)
		return (0);
	if (ft_is_clean(stack_a))
	{
		ft_print_nodes(*stack_a);
		ft_lst_delete(stack_a);
		ft_lst_delete(stack_b);
		return (0);
	}
	ft_sort(stack_a, stack_b);
	ft_print_nodes(*stack_a);
	ft_lst_delete(stack_a);
	ft_lst_delete(stack_b);
	return (0);
}
