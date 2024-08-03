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
/*     r_list *highest_number_a;
    r_list *highest_number_b; */

    int lst_size;

    lst_size = ft_lstsize((t_list *) a_stack);
/*     highest_number_a = high_number(*a_stack);
 *//*     highest_number_b = high_number_b(*b_stack);
 */
    while (lst_size > 3)
    {
        pb(a_stack, b_stack);
        lst_size--;
    }
    sort_five(a_stack, b_stack);



}