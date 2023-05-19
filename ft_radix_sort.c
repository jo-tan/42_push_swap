#include "ft_push_swap.h"

/*static int	ft_max_bits(t_list **stack_a)
{
	int		    max_index;
	int		    max_bits;

	max_index = ft_highest_index(stack_a);
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}*/

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list     *head;
	int		bit_position;
	int		j;
	int		max_bits;
	int		size;

    size = ft_lst_size(*stack_a);
    max_bits = 0;
    ft_print_nodes(*stack_a);
    while ((size - 1) >> max_bits != 0)
        max_bits++;
	bit_position = -1;
    ft_printf("size: %i\n", size);
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