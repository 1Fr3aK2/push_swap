/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:52:57 by marvin            #+#    #+#             */
/*   Updated: 2024/07/10 02:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int writing_errors(char *str)
{
    if (!str || *str == '\0')
        return (1);
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return(1);
    if(*str == '+' || *str == '-')
    {
        str++;
        if(!(*str >= '0' && (*str) <= '9'))
            return(1);
    }
    else if (*str < '0' && *str > '9')
        return (1);
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return (1);
        str++;
    }
    return (0);
}

int duplicate(r_list *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void free_stack(r_list **stack)
{
    r_list *temp;

    if(!stack || !(*stack))
        return ;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}


void free_message(r_list **stack, r_list **b_stack)
{
    free_stack(stack);
    free_stack(b_stack);
    ft_printf("Error, freeing stacks ...\n");
    exit(1);
}

/* int main()
{
    char *str = "+11111111111111111111111111111a1";
    int temp;
    temp = writing_errors(str);
    printf("%d\n", temp);
    write("Error, freeing stacks ...\n", 27); 
}
 */