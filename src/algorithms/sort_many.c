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
    /* int median;
    int counter;
    int original_counter; */
    /* r_list *lastnode; */
    
    if(!(*a_stack) || !(*a_stack)->next)
        return ;
    
    lst_size = ft_lstsize((t_list *)*a_stack);
    while(lst_size > 5)
    {   
        pb(a_stack, b_stack);      
        lst_size--;
    }
    sort_five(a_stack, b_stack);
    r_list *current_b = *b_stack;
    while (current_b) //saber o counter de cada elemento em falta
                        //implementar uma simulacao para verificar quando existem 2 counters iguais qual numero passar para a_stack
                        //opcao 1: verificar qual o menor numero
                        //opcao 2: verificar o menor numero de operacoes necessarias
    {
        static int i = 0;
        compare(&current_b, a_stack, &(current_b->counter));
        printf("Counter %d: %d, number: %d\n", ++i,  current_b->counter, current_b->number);
        current_b = current_b->next;
    }
    min_counter = find_min_counter(*b_stack);
    ft_printf("min counter number is: %d\n", min_counter->number);
    //descobrir o menor counter com find_min ...
}
   /*  while(*b_stack)
    {
        static int i = 0;
        compare(&(*b_stack), &(*a_stack), &(*b_stack)->counter);
        ft_printf("counter %d: %d\n", ++i, (*b_stack)->counter);     
        (*b_stack) = (*b_stack) -> next;
    } */



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
