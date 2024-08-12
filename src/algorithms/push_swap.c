/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:02:18 by marvin            #+#    #+#             */
/*   Updated: 2024/08/02 17:02:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_swap(r_list **a_stack, r_list **b_stack)
{
    int lst_size;
    r_list *lastnode;
    if(!(*a_stack) || !(*a_stack)->next)
        return ;
    
    lst_size = ft_lstsize((t_list *)*a_stack);
    lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);
    while(lst_size > 5)
    {
        if((*a_stack)->number < lastnode -> number)
            pb(a_stack, b_stack);
        else
        {
            rra(a_stack);
            pb(a_stack, b_stack);
            lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);
        }      
        lst_size--;
    }
    sort_five(a_stack, b_stack);
} 