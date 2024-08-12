#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct p_list
{
	int			    number;
    int             index;
	struct p_list	*next;
    struct p_list   *prev;
}					r_list;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if(!lst)
		return (0);
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void push_swap(r_list **a_stack, r_list **b_stack)
{
    int lst_size;
    if(!(*a_stack) || !(*a_stack)->next)
        return ;

    lst_size = ft_lstsize((t_list *)*a_stack);
    printf("Tamanho da pilha: %d\n", lst_size);
    printf("tamanho de metade da pilha : %d\n", lst_size/2);
    while
}

r_list *new_node(int number)
{
    r_list *node = (r_list *)malloc(sizeof(r_list));
    node->number = number;
    node->index = 0;  // índice pode ser definido conforme necessário
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void add_node_front(r_list **stack, r_list *new_node)
{
    if (*stack != NULL)
        (*stack)->prev = new_node;
    new_node->next = *stack;
    *stack = new_node;
}

int main(void)
{
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;

    // Adiciona alguns elementos na pilha A
    add_node_front(&a_stack, new_node(3));
    add_node_front(&a_stack, new_node(1));
    add_node_front(&a_stack, new_node(5));
    add_node_front(&a_stack, new_node(2));
    add_node_front(&a_stack, new_node(4));

    // Chama a função push_swap
    push_swap(&a_stack, &b_stack);

    // Libera a memória (opcional, mas recomendado)
    r_list *temp;
    while (a_stack != NULL)
    {
        temp = a_stack;
        a_stack = a_stack->next;
        free(temp);
    }

    return 0;
}
