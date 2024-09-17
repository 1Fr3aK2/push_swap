/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:56:33 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 02:56:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_three(r_list **stack)
{
    r_list *highest_number;

    if (!(*stack) || !(*stack) -> next)
        return ;
    highest_number = high_number(*stack);
    if((*stack)->number == highest_number->number)
        ra(stack);
    if((*stack)->next->number == highest_number->number)
        rra(stack);
    if((*stack)->number > (*stack)->next->number)
        sa(stack);
    printf("sort_3 done\n");
}