/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:48:30 by marvin            #+#    #+#             */
/*   Updated: 2024/08/13 18:48:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void sort_many(r_list **a_stack, r_list **b_stack)
{
    int lst_size;
    int median;
    int counter;
    int original_counter;
    /* r_list *lastnode; */
    
    if(!(*a_stack) || !(*a_stack)->next)
        return ;
    
    lst_size = ft_lstsize((t_list *)*a_stack);
    /* lastnode = (r_list *)ft_lstlast((t_list *)*a_stack); */
    
    // Movendo nodes para b_stack até restarem apenas 5 em a_stack
/*     while(lst_size > 3) //trocar para 3
    {
        if((*a_stack)->number < lastnode->number)
            pb(a_stack, b_stack);
        else
        {
            rra(a_stack);
            pb(a_stack, b_stack);
            lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);
        }      
        lst_size--;
    } */
   while(lst_size > 3) //trocar para 3
    {   
        pb(a_stack, b_stack);      
        lst_size--;
    }
    /* sort_five(a_stack, b_stack); */
    sort_three(a_stack);
    
    while(*b_stack)
    {
        counter = 0;
        original_counter = compare(b_stack, a_stack, &counter);
        median = ft_lstsize((t_list *)*a_stack) / 2;
        
        if(original_counter > median)
        {
            while(counter--)
                rra(a_stack);
            pa(b_stack, a_stack);
            ra(a_stack);
            while(original_counter--)
                ra(a_stack);
            
        }
        else
        {
            while(counter--)
                ra(a_stack);
            pa(b_stack, a_stack);
            while(original_counter--)
                rra(a_stack);
        }
        lst_size =  ft_lstsize((t_list *)*a_stack);
    }
}
