/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:20:25 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:20:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
 
static void push(r_list **a_stack, r_list **b_stack)
{
    r_list  *temp_a;
    r_list  *temp_b;

    if(!(*a_stack))
        return ;
    temp_a = (*a_stack);
    (*a_stack) = (*a_stack) -> next;
    if(*a_stack)
        (*a_stack) -> prev = NULL;
    temp_a -> prev = NULL;
    if (!(*b_stack))
    {
        (*b_stack) = temp_a;
        (*b_stack) -> next = NULL;
    }
    else
    {
        temp_b = (*b_stack);
        (*b_stack) = temp_a;
        (*b_stack) -> next = temp_b;
        temp_b->prev = temp_a;
    }
}

void pa(r_list **b_stack, r_list **a_stack)
{
    push(b_stack, a_stack);
    ft_printf("pa\n");
}


void pb(r_list **a_stack, r_list **b_stack)
{
    push(a_stack, b_stack);
    ft_printf("pb\n");
}