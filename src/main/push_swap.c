/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:58:28 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 20:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Função que processa os argumentos e imprime o resultado
void process_args(int argc, char *argv[])
{
    if (argc < 2) {
        ft_printf("Número insuficiente de argumentos.\n");
        return;
    }

    ft_printf("Número de argumentos: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        ft_printf("Argumento %d: %s\n", i, argv[i]);
    }
    
}


int main(int argc, char *argv[])
{
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;
    int size;
    char **split_argv = NULL;

    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
    {
        ft_printf("Número insuficiente de argumentos.\n");
        return 1;
    }
    if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        if (!split_argv)
        {
            ft_printf("Erro ao dividir a string.\n");
            return 1;
        }
        argv = split_argv;
        // Atualize argc para refletir o número correto de argumentos após a divisão
        argc = 0;
        while (argv[argc])
            argc++;
    }
    else
    {
        // Incrementar o ponteiro argv para pular o nome do programa
        argv++;
        argc--;
    }

    process_args(argc, argv);

    init_stack(&a_stack, argv, argc);
    size = ft_lstsize((t_list *)a_stack);

    ft_printf("a_stack antes de ordenar: ");
    r_list *temp_itera = a_stack; // Create a separate variable for iteration
    while (temp_itera)
    {
        ft_printf("%d ", temp_itera->number);
        temp_itera = temp_itera->next;
    }
    ft_printf("\n");
    if (verify(a_stack) == 1)
    {
        if (size == 2)
            sa(&a_stack);
        else if (size == 3)
            sort_three(&a_stack);
        else if (size <= 5)
            sort_five(&a_stack, &b_stack);
        else
            sort_many(&a_stack, &b_stack);
    }

    // Imprimir a pilha 'a_stack'
    ft_printf("a_stack depois de ordenar: ");
    r_list *temp_iter = a_stack; // Create a separate variable for iteration
    while (temp_iter)
    {
        ft_printf("%d ", temp_iter->number);
        temp_iter = temp_iter->next;
    }
    ft_printf("\n");

/*     ft_printf("b_stack : ");
    r_list *temp_iteraa = b_stack; // Create a separate variable for iteration
    while (temp_iteraa)
    {
        ft_printf("%d ", temp_iteraa->number);
        temp_iteraa = temp_iteraa->next;
    }
    ft_printf("\n"); */

    if (split_argv)
        free_split(split_argv);

    free_stack(&a_stack);
    free_stack(&b_stack);
    return 0;
}