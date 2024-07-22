/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:43:50 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 04:43:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void init_stack(r_list **stack, char *argv[])
{
    long number;
    int i;

    i = 0;
    while(argv[i])
    {
        if(writing_errors(argv[i]) == 1)
            free_message(stack);
        number = ft_atol(argv[i]);
        if(number > INT_MAX || number < INT_MIN)
            free_message(stack);
        if(duplicate(*stack, (int)number))
            free_message(stack);
        add_node(stack, (int)number);
        i++;
    }
}
