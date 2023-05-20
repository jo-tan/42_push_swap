/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:05 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 18:33:13 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_valid_nb(const char *nptr)
{
	if (!nptr || *nptr == '\0')
		return (0);
	if ((*nptr == '+' && *(nptr + 1) != '\0')
		|| (*nptr == '-' && *(nptr + 1) != '\0'))
		nptr++;
	while (*nptr != '\0')
	{
		if (*nptr < '0' || *nptr > '9')
			return (0);
		nptr++;
	}
	return (1);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			neg_sign;
	long int	res;

	i = 0;
	neg_sign = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg_sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = 10 * res + (nptr[i] - '0');
		i++;
	}
	if (neg_sign == 1)
		res *= -1;
	return (res);
}
