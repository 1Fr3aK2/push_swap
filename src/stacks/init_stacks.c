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

void init_stack(r_list **stack, char **argv, int argc) 
{   
    r_list *node;
    r_list *last = NULL; // Ponteiro para o último nó da lista
    long number;
    int i;

    i = 0;

    while (i < argc)
    {
        // Verifica se há erros de escrita antes de converter
        if (writing_errors(argv[i]))
        {
            /* ft_printf("Error of syntax!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            return;
        }

        // Converte o argumento para número e verifica se está dentro dos limites
        number = ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
        {
            /* ft_printf("Error, the number is outside of Integer limits!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            return;
        }

        // Verifica se o número já está na stack
        if (duplicate(*stack, (int)number))
        {
            /* ft_printf("Error, duplicated numbers!\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            return;
        }

        // Cria um novo node
        node = malloc(sizeof(r_list));
        if (!node)
        {
            /* ft_printf("Malloc failed\n"); */
            write(2, "Error\n", 6);
            free_stack(stack);
            return;
        }
        node->number = (int)number;
        node->next = NULL;
        node->prev = NULL;
        node->counter = 0;
        
        if (*stack == NULL)
        {
            // Se a lista estiver vazia, o novo nó será o primeiro nó
            *stack = node;
        }
        else
        {
            // Adiciona o novo nó ao final da lista
            last->next = node;
            node->prev = last;
        }
        last = node; // Atualiza o último nó para o novo nó

        i++;
    }   
}

