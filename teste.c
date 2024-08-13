#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura r_list
typedef struct r_list {
    int number;
    struct r_list *next;
} r_list;

// Função para criar um novo nó na lista
r_list *create_node(int number) {
    r_list *new_node = (r_list *)malloc(sizeof(r_list));
    new_node->number = number;
    new_node->next = NULL;
    return new_node;
}

// Função compare fornecida
int compare(r_list **b_stack, r_list **a_stack, int *counter) {
    if (!(*a_stack) || !(*b_stack))
        return 1;

    *counter = 0;  // Inicializa o contador
    while (*b_stack && *a_stack) {
        if ((*b_stack)->number > (*a_stack)->number) {
            (*counter)++;
            *a_stack = (*a_stack)->next;
        } else {
            break;
        }
    }
    return *counter;  // Retorna o valor do contador
}

// Função para imprimir uma lista
void print_stack(r_list *stack) {
    while (stack) {
        printf("%d ", stack->number);
        stack = stack->next;
    }
    printf("\n");
}

// Função principal
int main() {
    // Criação da lista a_stack
    r_list *a_stack = create_node(10);
    a_stack->next = create_node(20);
    a_stack->next->next = create_node(30);

    // Criação da lista b_stack
    r_list *b_stack = create_node(25);
    b_stack->next = create_node(5);
    b_stack->next->next = create_node(35);

    // Imprimindo as listas antes da comparação
    printf("a_stack antes da comparação:\n");
    print_stack(a_stack);
    printf("b_stack antes da comparação:\n");
    print_stack(b_stack);

    // Criando ponteiros para as listas e o contador
    r_list *a_ptr;
    r_list *b_ptr = b_stack;
    int counter;

    // Testando a função compare com vários elementos de b_stack
    while (b_ptr) {
        a_ptr = a_stack;  // Reinicia o ponteiro para o início de a_stack
        int position = compare(&b_ptr, &a_ptr, &counter);
        printf("Elemento %d de b_stack deve ser inserido na posição %d de a_stack\n", b_ptr->number, position);
        b_ptr = b_ptr->next;  // Avança para o próximo elemento de b_stack
    }

    // Imprimindo as listas após a comparação
    printf("a_stack após a comparação:\n");
    print_stack(a_stack);
    printf("b_stack após a comparação:\n");
    print_stack(b_stack);

    // Liberando a memória alocada
    while (a_stack != NULL) {
        r_list *temp = a_stack;
        a_stack = a_stack->next;
        free(temp);
    }

    while (b_stack != NULL) {
        r_list *temp = b_stack;
        b_stack = b_stack->next;
        free(temp);
    }

    return 0;
}
