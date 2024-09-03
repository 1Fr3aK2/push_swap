#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
/* #include "../includes/libft/libft.h"
#include "../includes/libft/ft_printf/ft_printf.h" */

typedef struct p_list
{
	int			    number;
    int             counter;
	struct p_list	*next;
    struct p_list   *prev;

} r_list;

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
int main()
{
    // Criando manualmente a lista ligada
    r_list *head = malloc(sizeof(r_list));
    r_list *second = malloc(sizeof(r_list));
    r_list *third = malloc(sizeof(r_list));

    head->counter = 10;
    head->next = second;

    second->counter = 50;
    second->next = third;

    third->counter = 5;
    third->next = NULL;

    // Encontrando o nó com o menor valor de counter
    r_list *min_node = find_min_counter(head);

    if (min_node)
        printf("O menor counter é: %d\n", min_node->counter);
    else
        printf("A lista está vazia.\n");

    // Liberando memória
    free(third);
    free(second);
    free(head);

    return 0;
}























#include "../../includes/push_swap.h"

void sort_five(r_list **a_stack, r_list **b_stack)
{
    r_list *highest_number_b;
    r_list *highest_number_a;
    r_list *lowest_number_a;
    int lst_size;

    if (!(*a_stack) || !(*a_stack)->next)
        return;

    lst_size = ft_lstsize((t_list *)*a_stack);
    
    // Move two elements to b_stack if list size > 3
    while (lst_size > 3)
    {
        pb(a_stack, b_stack);
        lst_size--;
    }

    sort_three(a_stack); // Sort the 3 elements in a_stack

    while (*b_stack)
    {
        highest_number_a = high_number(*a_stack);
        lowest_number_a = low_number(*a_stack);
        highest_number_b = high_number(*b_stack);

        if ((*b_stack)->number != highest_number_b->number)
        {
            if ((*b_stack)->number < lowest_number_a->number)
            {
                pa(b_stack, a_stack);
            }
            else if ((*b_stack)->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
            }
            else if ((*b_stack)->number > lowest_number_a->number && (*b_stack)->number > highest_number_a->prev->number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }
        else
        {
            if (highest_number_b->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
            }
            else if (highest_number_b->number < lowest_number_a->number)
            {
                pa(b_stack, a_stack);
            }
            else if (highest_number_b->number > lowest_number_a->number && highest_number_b->number > highest_number_a->prev->number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }

        // Ensure the stack size is updated after each operation
        lst_size = ft_lstsize((t_list *)*a_stack);
    }
}
