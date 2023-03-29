/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:23 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/28 17:21:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h> //read(), write(), exit()
# include <stdlib.h> //malloc(), free()
# include <stdarg.h> //ft_printf()

typedef struct s_list
{
	int				*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_lst_new(int *data);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *nptr);
int		ft_printf(const char *s, ...);
int		ft_vprintf(const char s, va_list ap);
int		ft_print_c(int c);
int		ft_print_s(char *s);
int		ft_print_d_i(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n, char c);
int		ft_print_p(unsigned long n);

#endif
