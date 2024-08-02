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
void process_args(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Número insuficiente de argumentos.\n");
        return;
    }

    printf("Número de argumentos: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    
    // Adicione mais verificações e depuração aqui para analisar o problema
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

int main(int argc, char *argv[])
{
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;
    int size;
    char **split_argv = NULL;

    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
    {
        printf("Número insuficiente de argumentos.\n");
        return 1;
    }
    if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        if (!split_argv)
        {
            printf("Erro ao dividir a string.\n");
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

    if (verify(a_stack) == 1)
    {
        if (size == 2)
            sa(&a_stack);
        else if (size == 3)
            sort_three(&a_stack);
        else if (size == 5)
            sort_five(&a_stack, &b_stack);
        else
            push_swap(&a_stack, &b_stack);
    }

    // Imprimir a pilha 'a_stack'
    r_list *current = a_stack;
    while (current)
    {
        ft_printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");

    if (split_argv)
        free_split(split_argv);

    free_stack(&a_stack);
    free_stack(&b_stack);
    return 0;
}