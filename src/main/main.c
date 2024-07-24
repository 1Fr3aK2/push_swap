/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:58:28 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 20:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int main(int argc, char *argv[])
{
    r_list *a_stack;
    r_list *b_stack;
    long number;

    a_stack = NULL;
    b_stack = NULL;
    
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (1);

    number = ft_atol(argv[1]);

    if(writing_errors(argv[1]) == 1 || duplicate(a_stack, (int)number) ||
                            number > INT_MAX || number < INT_MIN)
        free_message(&a_stack);
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    add_node(&a_stack, (int)number);
    init_stack(&a_stack, argv + 1);
    if (verify(a_stack) == 1)
    {
        if (ft_lstsize((t_list *)a_stack) == 2)
            sa(&a_stack);
        else if (ft_lstsize((t_list *)a_stack) == 3)
            sort_three(&a_stack);
        else if (ft_lstsize((t_list *)a_stack) == 5)
            sort_five(&a_stack);
    }
    free_stack(&a_stack);
    return (0);
} */

int main(int argc, char *argv[])
{
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;
    int size;
    
    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');

    init_stack(&a_stack, argv);
    size = ft_lstsize((t_list *)a_stack);
    if (verify(a_stack) == 1)
    {
        if (size == 2)
            sa(&a_stack);
        else if (size == 3)
            sort_three(&a_stack);
        else if (size == 5)
            sort_five(&a_stack, &b_stack);
    }

    while (a_stack)
    {
        printf("%d ", a_stack->number);
        a_stack = a_stack->next;
    }

    free_stack(&a_stack);
    free_stack(&b_stack);
    return (0);
}
