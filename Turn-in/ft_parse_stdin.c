/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:24:00 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 21:53:35 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_valid_arg(const char *s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[len])
		len++;
	while (s[i])
	{
		if (s[i] == ' ')
			j++;
		else if (s[i] == '+' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			j++;
		else if (s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			j++;
		else if (s[i] >= '0' && s[i] <= '9')
			j++;
		i++;
	}
	if (j != len)
		return (0);
	return (1);
}

void	ft_parse_arg(t_list **stack_a, const char *s)
{
	t_list		*new;
	char		**args;
	int			i;
	long int	nbr;

	i = 0;
	args = ft_split(s, ' ');
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (ft_error(stack_a));
		new = ft_lst_new(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		free(args[i]);
		i++;
	}
	free(args);
}
