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
	t_list	*head; // a dummy head
	t_list	*tail;
	int		*nbr;

	head = ft_lst_new(NULL);
	tail = head;
	if (ac <= 1)
		return (0);
	else
	{
		while (ac > 1)
		{
			nbr = ft_atoi(av[i])
		}
	}
	return (0);
}
