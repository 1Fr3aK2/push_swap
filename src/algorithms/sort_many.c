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
    r_list *min_counter;
    r_list *current_b;
    /* int median;
    int counter;
    int original_counter; */

    if(!(*a_stack) || !(*a_stack)->next)
        return ;
    
    lst_size = ft_lstsize((t_list *)*a_stack);
    while(lst_size > 5)
    {   
        pb(a_stack, b_stack);      
        lst_size--;
    }
    sort_five(a_stack, b_stack);
    current_b = *b_stack;
    compare(&current_b, a_stack);
    while (current_b)
    {
        static int i = 0;
        printf("\nCounter %d: %d, number: %d\n", ++i,  current_b->counter, current_b->number);
        current_b = current_b->next;
    }
    min_counter = find_min_counter(*b_stack);
    ft_printf("min counter number is: %d\n", min_counter->number);
    min_to_top(b_stack, a_stack);
    //organizar a_stack


}

    /* int i = compar0e_inside(b_stack);
    printf("compare inside: %d\n", i); */
    /* int i = compare_inside((b_stack));
    printf("compare inside %d\n", i); */
    //descobrir o menor counter com find_min ...


/*     while(*b_stack)
    {
        compare(b_stack, a_stack, &(*b_stack)->counter);
    }
    ft_printf("counter: %d\n", (*b_stack)->counter); */
/*     while(*b_stack)
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
    } */
