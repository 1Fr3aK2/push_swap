#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct p_list {
    int number;
    struct p_list *next;
    struct p_list *prev;
} r_list;

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

r_list *new_node(int number) {
    r_list *node = (r_list *)malloc(sizeof(r_list));
    if (node) {
        node->number = number;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

void add_node(r_list **head, int number) {
    r_list *node = new_node(number);
    if (!node) return;

    node->next = *head;
    if (*head) (*head)->prev = node;
    *head = node;
}

void print_list(r_list *list) {
    while (list) {
        printf("%d ", list->number);
        list = list->next;
    }
    printf("\n");
}

void free_list(r_list *list) {
    r_list *temp;
    while (list) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

static void push(r_list **a_stack, r_list **b_stack)
{
    r_list  *temp_a;
    r_list  *temp_b;

    if(!(*a_stack))
        return ;
    temp_a = (*a_stack);
    (*a_stack) = (*a_stack) -> next;
    if(*a_stack)
        (*a_stack) -> prev = NULL;
    temp_a -> prev = NULL;
    if (!(*b_stack))
    {
        (*b_stack) = temp_a;
        (*b_stack) -> next = NULL;
    }
    else
    {
        temp_b = (*b_stack);
        (*b_stack) = temp_a;
        (*b_stack) -> next = temp_b;
        temp_b->prev = temp_a;
    }
}

void pa(r_list **b_stack, r_list **a_stack)
{
    push(b_stack, a_stack);
    printf("pa\n");
}


void pb(r_list **a_stack, r_list **b_stack)
{
    push(a_stack, b_stack);
    printf("pb\n");
}

static void swap(r_list **stack)
{
    r_list *temp;

     if(!(*stack) || !(*stack) -> next)
        return ;
        
    temp = (*stack);
    (*stack) = (*stack) -> next;
    temp -> next = (*stack) -> next;
    (*stack) -> next = temp;

    (*stack) -> prev = NULL;
    temp -> prev = (*stack);
    temp -> next -> prev = temp;

}


void sa(r_list **a_stack)
{
    swap(a_stack);
    printf("sa\n");
}

void sb(r_list **b_stack)
{
    swap(b_stack);
    printf("sb\n");
}

r_list	*ft_lstlast(r_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void rotate(r_list **stack)
{
    r_list  *temp;
    r_list  *lastnode;

    if(!(*stack) || !(*stack) -> next)
        return ;
    else
    {
        temp = (*stack); // guardar o node 1
        (*stack) = (*stack) -> next; // definir o node1 -> node2
        lastnode = (r_list *)ft_lstlast(*stack); // encontrar o ultimo node
        (*stack)->prev = NULL;
        lastnode -> next = temp;
        temp -> prev = lastnode;
        temp -> next = NULL; // ultimo node passa a ser o node 1
    }
}   

void ra(r_list **a_stack)
{
    rotate(a_stack);
    printf("ra\n");
}

void rb(r_list **b_stack)
{
    rotate(b_stack);
    printf("rb\n");
}

void rr(r_list **a_stack, r_list **b_stack)
{
    rotate(a_stack);
    rotate(b_stack);
    printf("rr\n");
}

static void reverse(r_list **stack)
{
    r_list *temp;
    r_list *lastnode;
    
    if (!(*stack) || !(*stack) -> next)
        return ;
    lastnode = (r_list *)ft_lstlast(*stack);
    temp = (*stack);
    lastnode -> prev -> next = NULL;
    (*stack) = lastnode;
    lastnode -> next = temp;
    lastnode -> prev = NULL;
}

void rra(r_list **a_stack)
{
    reverse(a_stack);
    printf("rra\n");
}

void rrb(r_list **b_stack)
{
    reverse(b_stack);
    printf("rrb\n");
}

void rrr(r_list **a_stack, r_list **b_stack)
{
    reverse(a_stack);
    reverse(b_stack);
    printf("rrr\n");
}


r_list *high_number(r_list *stack) 
{
    r_list *highest_number;

    // Verifique se a pilha é nula
    if (!stack)
        return NULL;

    // Inicializa o nó mais alto como o primeiro nó da pilha
    highest_number = stack;

    // Percorre a pilha até o final
    while (stack->next) 
    {
        stack = stack->next;
        // Atualiza o nó mais alto se o nó atual tiver um número maior
        if (stack->number > highest_number->number)
            highest_number = stack;
    }
    return highest_number;
}


void sort_three(r_list **stack)
{
    r_list *highest_number;

    if (!(*stack) || !(*stack) -> next)
        return ;
    highest_number = high_number(*stack);
    if((*stack)->number == highest_number->number)
        ra(stack);
    if((*stack)->next->number == highest_number->number)
        rra(stack);
    if((*stack)->number > (*stack)->next->number)
        sa(stack);
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




int verify(r_list *stack)
{
    if (!stack) 
        return 1; // Return 1 if stack is NULL (indicating it's not sorted)
        
    while (stack && stack->next) // Ensure stack and stack->next are not NULL
    {
        if (stack->number > stack->next->number)
            return 1; // Return 1 if the current element is greater than the next (not sorted)
        stack = stack->next;
    }
    return 0; // Return 0 if all elements are in ascending order
}

void sort_five(r_list **a_stack)
{
    r_list *b_stack = NULL;
    r_list *highest_number_b;
    r_list *highest_number_a;
    r_list  *lowest_number_a;
    int lst_size;

    if(!(*a_stack) || !(*a_stack)->next)
        return ;

    lst_size = ft_lstsize((t_list *)*a_stack);
    while(lst_size > 3)
    {
        pb(a_stack, &b_stack);
        lst_size--;
    }
    sort_three(a_stack);
    highest_number_a = high_number(*a_stack);
    lowest_number_a = low_number(*a_stack);
    highest_number_b = high_number(b_stack);
 

    while(b_stack)
    {
        if(b_stack && highest_number_b && b_stack->number != highest_number_b->number)
        {
            if(b_stack->number < lowest_number_a->number)
                pa(&b_stack, a_stack);
            else if(b_stack->number > lowest_number_a->number &&  b_stack->number > highest_number_a->prev-> number)
            {
                rra(a_stack);
                pa(&b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if(b_stack->number > lowest_number_a->number &&  b_stack-> number < highest_number_a->prev->number)
            {
                pa(&b_stack, a_stack);
                sa(a_stack);
            }
            else if(b_stack->number > highest_number_a->number)
            {
                pa(&b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
        }


        if(b_stack && highest_number_b && b_stack->number == highest_number_b->number)
        {
            if(highest_number_b->number > highest_number_a->number)
            {
                pa(&b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
            else if(highest_number_b->number < lowest_number_a->number)
            {
                pa(&b_stack, a_stack);
                lowest_number_a = low_number(*a_stack);
            }
            else if(highest_number_b->number > lowest_number_a->number && highest_number_b->number > highest_number_a->prev->number)
            {
                rra(a_stack);
                pa(&b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if(b_stack->number < highest_number_a ->number && b_stack->number > lowest_number_a->number && b_stack->number < highest_number_a->prev->number && b_stack->number > (*a_stack)->next->number)
            {
                ra(a_stack);
                pa(&b_stack, a_stack);
                sa(a_stack);
                rra(a_stack);
            }
            else if(highest_number_b->number < highest_number_a->number && highest_number_b->number > lowest_number_a->number && highest_number_b->number < lowest_number_a->next->number)
            {
                pa(&b_stack, a_stack);
                sa(a_stack);
            }
        }

        if(b_stack && highest_number_b->number == lowest_number_a->number)
        {
            pa(&b_stack, a_stack);
            lowest_number_a = low_number(*a_stack);
        } 
    }   
} 





int main(void) {
    r_list *a_stack = NULL;

    add_node(&a_stack, 87);
    add_node(&a_stack, 6);
    add_node(&a_stack, 45);
    add_node(&a_stack, 3);
    add_node(&a_stack, 34);


    printf("Antes de ordenar:\n");
    print_list(a_stack);

    sort_five(&a_stack);

    printf("Depois de ordenar:\n");
    print_list(a_stack);

    free_list(a_stack);

    return 0;
}





/* #include <stdio.h>
#include <stdlib.h>

typedef struct s_r_list {
    int number;
    struct s_r_list *next;
    struct s_r_list *prev;
} r_list;

r_list* low_number(r_list *stack) {
    r_list *min_node = stack;
    while (stack) {
        if (stack->number < min_node->number)
            min_node = stack;
        stack = stack->next;
    }
    return min_node;
}

r_list* high_number(r_list *stack) {
    r_list *max_node = stack;
    while (stack) {
        if (stack->number > max_node->number)
            max_node = stack;
        stack = stack->next;
    }
    return max_node;
}

int is_sorted(r_list *stack) {
    while (stack && stack->next) {
        if (stack->number > stack->next->number)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void ra(r_list **stack) {
    if (!(*stack) || !(*stack)->next)
        return;
    r_list *temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    r_list *last = *stack;
    while (last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;

    printf("ra\n");
}

void rra(r_list **stack) {
    if (!(*stack) || !(*stack)->next)
        return;
    r_list *last = *stack;
    while (last->next)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    printf("rra\n");
}

void sa(r_list **stack) {
    if (!(*stack) || !(*stack)->next)
        return;
    r_list *first = *stack;
    r_list *second = (*stack)->next;
    
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    first->prev = second;
    second->prev = NULL;
    *stack = second;

    printf("sa\n");
}

void pb(r_list **a_stack, r_list **b_stack) {
    if (!(*a_stack))
        return;
    r_list *temp = *a_stack;
    *a_stack = (*a_stack)->next;
    if (*a_stack)
        (*a_stack)->prev = NULL;

    temp->next = *b_stack;
    if (*b_stack)
        (*b_stack)->prev = temp;
    *b_stack = temp;

    printf("pb\n");
}

void pa(r_list **b_stack, r_list **a_stack) {
    if (!(*b_stack))
        return;
    r_list *temp = *b_stack;
    *b_stack = (*b_stack)->next;
    if (*b_stack)
        (*b_stack)->prev = NULL;

    temp->next = *a_stack;
    if (*a_stack)
        (*a_stack)->prev = temp;
    *a_stack = temp;

    printf("pa\n");
}

void sort_three(r_list **a_stack) {
    if (is_sorted(*a_stack))
        return;
    if ((*a_stack)->number > (*a_stack)->next->number)
        sa(a_stack);
    if (!is_sorted(*a_stack)) {
        rra(a_stack);
        if ((*a_stack)->number > (*a_stack)->next->number)
            sa(a_stack);
    }
}

int ft_lstsize(r_list *lst) {
    int size = 0;
    while (lst) {
        size++;
        lst = lst->next;
    }
    return size;
}

void sort_five(r_list **a_stack) {
    r_list *b_stack = NULL;
    r_list *highest_number_a;
    r_list *lowest_number_a;
    
    if (!(*a_stack) || !(*a_stack)->next)
        return;

    int lst_size = ft_lstsize(*a_stack);
    while (lst_size > 3) {
        pb(a_stack, &b_stack);
        lst_size--;
    }
    
    sort_three(a_stack);
    highest_number_a = high_number(*a_stack);
    lowest_number_a = low_number(*a_stack);

    while (b_stack) {
        if (b_stack->number < lowest_number_a->number || b_stack->number > highest_number_a->number) {
            pa(&b_stack, a_stack);
            if (b_stack->number > highest_number_a->number) {
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
        } else {
            while ((*a_stack)->number < b_stack->number && (*a_stack)->next->number > b_stack->number) {
                ra(a_stack);
            }
            pa(&b_stack, a_stack);
            if ((*a_stack)->number > (*a_stack)->next->number)
                sa(a_stack);
        }
        highest_number_a = high_number(*a_stack);
        lowest_number_a = low_number(*a_stack);
    }
    
    while (!is_sorted(*a_stack))
        ra(a_stack);
}

r_list *new_node(int number) {
    r_list *node = (r_list *)malloc(sizeof(r_list));
    node->number = number;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void print_list(r_list *lst) {
    while (lst) {
        printf("%d ", lst->number);
        lst = lst->next;
    }
    printf("\n");
}

int main() {
    r_list *stack = new_node(8);
    stack->next = new_node(14);
    stack->next->prev = stack;
    stack->next->next = new_node(37);
    stack->next->next->prev = stack->next;
    stack->next->next->next = new_node(22);
    stack->next->next->next->prev = stack->next->next;
    stack->next->next->next->next = new_node(5);
    stack->next->next->next->next->prev = stack->next->next->next;

    printf("Original list:\n");
    print_list(stack);

    sort_five(&stack);

    printf("Sorted list:\n");
    print_list(stack);

    return 0;
}
 */

