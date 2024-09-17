/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:16:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 19:16:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
 
void sort_five(r_list **a_stack, r_list **b_stack)
{
    r_list *highest_number_b;
    r_list *highest_number_a;
    r_list *lowest_number_a;
    int lst_size;

    if(!(*a_stack) || !(*a_stack)->next)
        return ;

    lst_size = ft_lstsize((t_list *)*a_stack);
    if(lst_size < 5)
        return ;
    while(lst_size > 3)
    {
        pb(a_stack, b_stack);
        lst_size--;
    }
    sort_three(a_stack);
    highest_number_a = high_number(*a_stack);
    lowest_number_a = low_number(*a_stack);
    highest_number_b = high_number(*b_stack);
    lst_size = ft_lstsize((t_list *)*a_stack);

    while(*b_stack && lst_size <= 5)
    {
        if (lst_size == 5)
            break ;
        else if(*b_stack && highest_number_b && (*b_stack)->number != highest_number_b->number)
        {
            if((*b_stack)->number < lowest_number_a->number)
                pa(b_stack, a_stack);
            else if((*b_stack)->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
            else if((*b_stack)->number > lowest_number_a->number &&  (*b_stack)->number > highest_number_a->prev-> number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if((*b_stack)->number > lowest_number_a->number && (*b_stack)-> number < highest_number_a->prev->number)
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }

        else if(*b_stack && highest_number_b && (*b_stack)->number == highest_number_b->number)
        {
            if(highest_number_b->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
            else if(highest_number_b->number < lowest_number_a->number)
            {
                pa(b_stack, a_stack);
                lowest_number_a = low_number(*a_stack);
            }
            else if(highest_number_b->number > lowest_number_a->number && highest_number_b->number > highest_number_a->prev->number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if((*b_stack)->number < highest_number_a ->number && (*b_stack)->number > lowest_number_a->number && (*b_stack)->number < highest_number_a->prev->number && (*b_stack)->number > (*a_stack)->next->number)
            {
                ra(a_stack);
                pa(b_stack, a_stack);
                sa(a_stack);
                rra(a_stack);
            }
            else if(highest_number_b->number < highest_number_a->number && highest_number_b->number > lowest_number_a->number && highest_number_b->number < lowest_number_a->next->number)
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }
        if ((*a_stack)->number > (*a_stack)->next->number)
            sa(a_stack);
        if(*b_stack && highest_number_b->number == lowest_number_a->number)
        {
            pa(b_stack, a_stack);
            lowest_number_a = low_number(*a_stack);
        }
        lst_size = ft_lstsize((t_list *)*a_stack);
        if(verify(*a_stack) == 1)
        {
            sort_five(a_stack, b_stack);
        }
    }
    printf("sort_five done\n");
}