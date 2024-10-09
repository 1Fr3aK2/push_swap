/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:01:39 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 19:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "../includes/libft/libft.h"
#include "../includes/libft/ft_printf/ft_printf.h"

typedef struct p_list
{
	int			    number;
    int             index;
	struct p_list	*next;
    struct p_list   *prev;

}					r_list;

//moves
/* static void push(r_list **b_stack, r_list **a_stack); */
void pa(r_list **a_stack, r_list **b_stack);
void pb(r_list **a_stack, r_list **b_stack);

/* static void reverse(r_list **stack); */
void rra(r_list **a_stack);
void rrb(r_list **b_stack);
void rrr(r_list **a_stack, r_list **b_stack);

/* static void swap(r_list **stack); */
void sa(r_list **a_stack);
void sb(r_list **b_stack);
void ss(r_list **a_stack, r_list **b_stack);

/* static void rotate(r_list **stack); */
void ra(r_list **a_stack);
void rb(r_list **b_stack);
void rr(r_list **a_stack, r_list **b_stack);

//algorithms
void sort_three(r_list **stack);
void sort_five(r_list **a_stack, r_list **b_stack);

//errors
int writing_errors(char *str);
int duplicate(r_list *stack, int n);
void free_stack(r_list **stack);

//utils
long	ft_atol(const char *str);
r_list *high_number(r_list *stack);
r_list *low_number(r_list *stack); 
void free_split(char **str);


//stacks
void init_stack(r_list **stack, char **argv, int argc);
int verify(r_list *stack);

//main
int main(int argc, char *argv[]);



#endif