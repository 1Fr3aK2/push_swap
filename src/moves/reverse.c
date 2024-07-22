/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:20:28 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:20:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

static void reverse(r_list **stack)
{
    r_list *temp;
    r_list *lastnode;
    
    if (!(*stack) || !(*stack) -> next)
        return ;
    lastnode = (r_list *)ft_lstlast((t_list *)stack);
    temp = (*stack);
    lastnode -> prev -> next = NULL;
    (*stack) = lastnode;
    lastnode -> next = temp;
    lastnode -> prev = NULL;
}

void rra(r_list **a_stack)
{
    reverse(a_stack);
    ft_printf("rra\n");
}

void rrb(r_list **b_stack)
{
    reverse(b_stack);
    ft_printf("rrb\n");
}

void rrr(r_list **a_stack, r_list **b_stack)
{
    reverse(a_stack);
    reverse(b_stack);
    ft_printf("rrr\n");
}