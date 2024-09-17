#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista encadeada
typedef struct r_list {
    int number;
    struct r_list *next;
} r_list;

// Função fornecida para comparar os números
int compare_numbers(r_list **stack) // saber quantos numeros com maior counter existem
{
    r_list *current_next;
    r_list *current_a;
    int counter;

    if (!(*stack))
        return 1;

    current_a = (*stack);
    current_next = (*stack)->next;
    if (!current_a || !current_next)
        return 1;

    counter = 0;
    while (current_next) {
        if (current_next->number < current_a->number) {
            counter++;
            current_next = current_next->next;
        } else
            break;
    }
    return counter;
}

// Função para criar um novo nó na lista
r_list *create_node(int number) {
    r_list *new_node = (r_list *)malloc(sizeof(r_list));
    if (!new_node) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    new_node->number = number;
    new_node->next = NULL;
    return new_node;
}

// Função para adicionar um nó ao início da lista
void push(r_list **stack, int number) {
    r_list *new_node = create_node(number);
    new_node->next = *stack;
    *stack = new_node;
}

// Função para liberar a memória da lista
void free_list(r_list *stack) {
    r_list *temp;
    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main() {
    r_list *stack = NULL;

    // Adicionando alguns números à lista
    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 8);
    push(&stack, 1);
    push(&stack, 9); // Lista: 9 -> 1 -> 8 -> 3 -> 5

    // Chamando a função compare_numbers
    while (stack)
    {
        int result = compare_numbers(&stack);
        printf("O resultado da comparação é: %d\n", result);
        stack = stack->next;
    }
    

    // Liberando a memória da lista
    free_list(stack);

    return 0;
}
