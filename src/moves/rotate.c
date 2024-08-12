/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:20:30 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 21:20:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void rotate(r_list **stack)
{
    r_list  *temp;
    r_list  *lastnode;

    if(!(*stack) || !(*stack) -> next)
        return ;
        
    temp = (*stack); // guardar o node 1
    (*stack) = (*stack) -> next; // definir o node1 -> node2
    lastnode = (r_list *)ft_lstlast((t_list *)*stack); // encontrar o ultimo node
    (*stack)->prev = NULL;
    lastnode -> next = temp;
    temp -> prev = lastnode;
    temp -> next = NULL; // ultimo node passa a ser o node 1
}  

void ra(r_list **a_stack)
{
    rotate(a_stack);
    ft_printf("ra\n");
}

void rb(r_list **b_stack)
{
    rotate(b_stack);
    ft_printf("rb\n");
}

void rr(r_list **a_stack, r_list **b_stack)
{
    rotate(a_stack);
    rotate(b_stack);
    ft_printf("rr\n");
}
