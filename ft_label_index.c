#include "ft_push_swap.h"
t_list  *ft_find_min(t_list **stack_a)
{
    t_list  *head;
    t_list  *runner;
    t_list  *min;
    int     find_min;

    head = *stack_a;
    runner = head;
    min = head;
    find_min = 0;
    while (runner)
        {
            if ((runner -> index == -1) && (!find_min || runner -> data < min -> data))
            {
                min = runner;
                find_min = 1;
            }
            runner = runner -> next;
        }
    return (min);
}

static int     ft_not_label(t_list **stack_a)
{
    t_list  *head;

    head = *stack_a;
    while (head)
    {
        if (head -> index == -1)
            return (1);
        head = head -> next;
    }
    return (0);
}

void    ft_label_index(t_list **stack_a)
{
    t_list *tmp;
    int index = 0;

    tmp = ft_find_min(stack_a);
    while (ft_not_label(stack_a) == 1) 
    {
        tmp -> index = index++;
        tmp = ft_find_min(stack_a);
    }
}