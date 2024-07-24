/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:58:18 by marvin            #+#    #+#             */
/*   Updated: 2024/07/13 01:58:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*void push_swap(r_list **a_stack, r_list **b_stack)
{
    r_list *temp;
    r_list *highest_number_a;
    r_list *lowest_number_a;
    r_list *highest_number_b;
    r_list *lowest_number_b;
    int size_lst;

    highest_number_a = high_number(*a_stack);
    lowest_number_a = low_number(*a_stack);
    highest_number_b = high_number(*b_stack);
    lowest_number_b = low_number(*b_stack);
}
    if(!(*a_stack) || !(*a_stack)->next)
        return ;
    size_lst = (r_list *)ft_lstsize((t_list *)*a_stack);
    while(size_lst > 3)
    {
        pa(b_stack, a_stack);
        size_lst--;
    }
    sort_three(a_stack);

    if(highest_number_b > highest_number_a)
    {

    } */


/* void push_swap(r_list **a_stack, r_list **b_stack)
{
    r_list *highest_number_b;
    r_list *lowest_number_b;
    r_list *highest_number_a;
    r_list *lowest_number_a;

    int stack_size;

    stack_size = ft_lstsize((t_list *)*a_stack);
    if(stack_size == 5)
        sort_five(a_stack);
    else
    {
        while(stack_size > 3)
        {
            pa(b_stack, a_stack);
            stack_size--;
        }
    }
    sort_three(a_stack);
    while(*b_stack)
    {
        highest_number_b = high_number(*b_stack);
        lowest_number_b = low_number(*b_stack);
        highest_number_a = high_number(*a_stack);
        lowest_number_a = low_number(*a_stack);
        if((*b_stack) -> number == highest_number_b -> number)
        {
            pb(a_stack, b_stack);
            if(*a_stack > highest_number_a)
            {
                ra(a_stack);
                highest_number_a = (*a_stack);
            }
        }
        else if ((*b_stack)->number == lowest_number_b ->number)
        {
            pb(a_stack, b_stack);
            if((*a_stack)->number < lowest_number_a ->number)
            {
                lowest_number_a = (*a_stack);
            }
        }
        



        }

} */