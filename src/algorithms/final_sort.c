/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:32:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 23:32:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void final_sort(r_list **a_stack)
{
    /* r_list *current_a; */
    r_list *highest_number;
    r_list *lastnode;
    r_list *lowest_number;
   /*  int median;
    int counter; */


    if(!(*a_stack))
        return ;

    highest_number = high_number(*a_stack);
    lowest_number = low_number(*a_stack);
    /* median = ft_lstsize((t_list *)*a_stack) / 2; */
    /* current_a = (*a_stack); */
    lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);
    while(verify((*a_stack)) == 1)
    {
        /* counter =  *//* compare_numbers(&(*a_stack)); */
        lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);
        if((*a_stack) -> number == highest_number->number)
            ra(a_stack);
        else if(lastnode->number == lowest_number->number)
            rra(a_stack);
        /* if(counter > median)
        {
            printf("counter of node->number: %d = %d\n", (*a_stack)->number, counter);
            while(counter--)
                rra(a_stack);
        }
        else if (counter < median)
        {
            while(counter--)
                ra(a_stack);
        }
    }  */   
    }
}

        /* lastnode = (r_list *)ft_lstlast((t_list *)*a_stack); */
        /* if((*a_stack)->number > (*a_stack)->next->number)
            sa(a_stack);
        else if((*a_stack)->number == highest_number->number)
            ra(a_stack);
        else if(lastnode->number == lowest_number->number)
            rra(a_stack); */