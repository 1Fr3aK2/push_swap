/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:03:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/12 04:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long ft_atol(const char *str)
{
	long number;
	int sign;

	number = 0;
	sign = 1;
	while((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}
	while(*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number *sign);
}

int verify(r_list *stack)
{
	if(!stack)
		return (1);
	while(stack -> next)
	{
		if(stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	return(0);
}

r_list *high_number(r_list *stack) 
{
    r_list *highest_number;
	
	highest_number = stack;

    if (!stack)
        return(NULL);
    while (stack->next) 
	{
        stack = stack->next;
        if (stack->number > highest_number->number)
            highest_number = stack;
    }
    return(highest_number);
} 

r_list *low_number(r_list *stack)
{
	r_list *lowest_number;

	lowest_number = stack;

	if(!stack)
		return(NULL);
	while(stack->next)
	{
		stack = stack->next;
		if(stack->number < lowest_number->number)
			lowest_number = stack;
	}
	return(lowest_number);
}

void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}


/* while(*b_stack)
    {
        lastbnode = (r_list *)ft_lstlast((t_list *)*b_stack);
        lastnode = (r_list *)ft_lstlast((t_list *)*a_stack);        
        if((*b_stack)->number > lastbnode -> number)
            pa(b_stack, a_stack);
        else 
        {   
            rrb(b_stack);
            pa(b_stack, a_stack);
            lastbnode = (r_list *)ft_lstlast((t_list *)*b_stack);

        }
    } */


int compare(r_list **b_stack, r_list **a_stack, int *counter)
{
    r_list *current_a;
    r_list *current_b;

    if (!(*a_stack) || !(*b_stack))
        return (1);

    current_a = *a_stack;
    current_b = *b_stack;
    (*counter) = (*b_stack)->counter; //0


    if (!current_b)
        return (0);

    while (current_a)
    {
        
        if (current_b->number > current_a->number)
            (*counter)++;
        current_a = current_a->next;
    }
    /* current_b->counter = *counter; */
    return (*counter);
}


r_list *find_min_counter(r_list *stack)
{
	r_list *min_counter;

	min_counter = stack;
	if(!stack)
		return (NULL);
	while(stack->next)
	{
        stack = stack->next;
		if(stack->counter < min_counter->counter)
			min_counter = stack;
	}
	return (min_counter);
}