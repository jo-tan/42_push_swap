/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:23 by jo-tan            #+#    #+#             */
/*   Updated: 2023/05/19 19:12:53 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h> //read(), write(), exit()
# include <stdlib.h> //malloc(), free()
# include <stdarg.h> //va_start(), va_end(), va_list()
# include <limits.h> //INT_MAX, INT_MIN

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

t_list		*ft_lst_new(int data);
t_list		*ft_lst_last(t_list *head);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		ft_lstadd_back(t_list **stack, t_list *new);
int			ft_lst_size(t_list *head);
void		ft_lst_delete(t_list **stack);
void		ft_print_nodes(t_list *head);
void		ft_free_stacks(t_list **stack_a, t_list **stack_b);
void		ft_error(t_list **stack);
long int	ft_atoi(const char *nptr);
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
int			ft_printf(const char *s, ...);
int			ft_vprintf(const char s, va_list ap);
int			ft_print_c(int c);
int			ft_print_s(char *s);
int			ft_print_d_i(int n);
int			ft_print_u(unsigned int n);
int			ft_print_x(unsigned int n, char c);
int			ft_print_p(unsigned long n);
int			ft_pa(t_list **stack_b, t_list **stack_a);
int			ft_pb(t_list **stack_a, t_list **stack_b);
int			ft_sa(t_list **stack_a);
int			ft_sb(t_list **stack_b);
int			ft_ss(t_list **stack_a, t_list **stack_b);
int			ft_ra(t_list **stack_a);
int			ft_rb(t_list **stack_b);
int			ft_rr(t_list **stack_a, t_list **stack_b);
int			ft_rra(t_list **stack_a);
int			ft_rrb(t_list **stack_b);
int			ft_rrr(t_list **stack_a, t_list **stack_b);
t_list		*ft_find_min(t_list **stack_a);
void		ft_label_index(t_list **stack_a);
int			ft_highest_index(t_list **stack_a);
int			ft_smallest_index(t_list **stack_a);
int			ft_min_position(t_list **stack_a);
void		ft_sort_3(t_list **stack_a);
void		ft_sort_4(t_list **stack_a, t_list **stack_b);
void		ft_sort_5(t_list **stack_a, t_list **stack_b);
void		ft_simple_sort(t_list **stack_a, t_list **stack_b);
void		radix_sort(t_list **stack_a, t_list **stack_b);
int			ft_is_valid_nb(const char *nptr);
int			ft_check_duplicate(t_list **stack_a);
int			ft_is_clean(t_list **stack_a);

#endif
