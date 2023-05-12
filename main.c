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

int	main(int ac, char **av)
{
	int	i = 1;
	t_list	*a_head; // a dummy head
	t_list	*tail;
	t_list	*b_head;
	int		*nbr = NULL;

	a_head = ft_lst_new(NULL);
	tail = a_head;
	if (ac <= 1)
		return (0);
	else
	{
		while (i < ac)
		{
			if (ft_is_valid_nb(av[i]))
			{
				nbr = malloc(sizeof(int));
				if (!nbr)
					return (0);
				*nbr = ft_atoi(av[i]);
				ft_printf("%i\n", *nbr);
				tail -> next = ft_lst_new(nbr);
				tail = tail -> next;
			}
			else
			{
				tail = a_head;
				a_head = a_head -> next;
				free (tail);
				ft_lst_delete(a_head);
				ft_printf("ERROR\n");
				return (0);
			}
			i++;
		}
		tail = a_head;
		a_head = a_head -> next;
		free (tail);
		b_head = ft_create_lst_b();
		ft_printf("Stack B is created. head value: %p\n", b_head -> data);
		ft_pb(&a_head, &b_head);
		ft_pb(&a_head, &b_head);
		ft_pb(&a_head, &b_head);
		ft_swap(&a_head);
		ft_swap(&b_head);
		ft_rr(&a_head, &b_head);
		ft_lst_delete(a_head);
		ft_printf("Stack A: all nodes are freed.\n");
		ft_lst_delete(b_head);
		ft_printf("Stack B: all nodes are freed.\n");
	}
	return (0);
}
