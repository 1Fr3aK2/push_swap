#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
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


t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
static void reverse(r_list **stack)
{
    r_list *temp;
    r_list *lastnode;
    
    if (!(*stack) || !(*stack)->next)
        return ;
    
    lastnode = (r_list *)ft_lstlast((t_list *)*stack);
    temp = (*stack);

    lastnode->prev->next = NULL;
    (*stack) = lastnode;
    lastnode->next = temp;
    lastnode->prev = NULL;
    temp->prev = lastnode;
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

static int	count_word(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i]) 
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}
// alocar memoria

static char	*word_aloc(const char *str, char c)
{
	char	*word;
	int		word_len;
	int		i;

	i = -1;
	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	word = (char *)malloc(word_len + 1);
	if (!word)
		return (NULL);
	while (++i < word_len)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

static void	*free_str(char **dest, int i)
{
	while (i >= 0)
		free(dest[i--]);
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	i = 0;
	dest = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c) 
			s++;
		if (*s) 
		{
			dest[i] = word_aloc(s, c); 
			if (!dest[i++])
				return (free_str(dest, i - 1), NULL);
		}
		while (*s && *s != c)
			s++;
	}
	dest[i] = 0;
	return (dest);
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


static void rotate(r_list **stack)
{
    r_list  *temp;
    r_list  *lastnode;

    if(!(*stack) || !(*stack) -> next)
        return ;
        
    temp = (*stack); // guardar o node 1
    (*stack) = (*stack) -> next; // definir o node1 -> node2
    lastnode = (r_list *)ft_lstlast((t_list *)*stack); // encontrar o ultimo node
    (*stack)->prev = NULL;
    lastnode -> next = temp;
    temp -> prev = lastnode;
    temp -> next = NULL; // ultimo node passa a ser o node 1
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

    if (!(*stack) || !(*stack)->next)
        return ;

    temp = (*stack);
    (*stack) = (*stack)->next;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    (*stack)->prev = NULL;
    temp->prev = (*stack);
    if (temp->next)
        temp->next->prev = temp;
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

void ss(r_list **a_stack, r_list **b_stack)
{
    swap(a_stack);
    swap(b_stack);
    printf("ss\n"); 
}
int writing_errors(char *str)
{
    if (!str || *str == '\0')
        return (1);
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
        return(1);
    if(*str == '+' || *str == '-')
    {
        str++;
        if(!(*str >= '0' && (*str) <= '9'))
            return(1);
    }
    else if (*str < '0' && *str > '9')
        return (1);
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return (1);
        str++;
    }
    return (0);
}

int duplicate(r_list *stack, int n)
{
	if (!stack)
		return (0);
    while (stack) 
    {
        if (stack->number == n)
            return 1;
        stack = stack->next;
    }
    return 0;
}

void free_stack(r_list **stack)
{
    r_list *current = *stack;
    r_list *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
void init_stack(r_list **stack, char **argv, int argc) 
{   
    r_list *node;
    r_list *temp;
    long number;
    int i;

    i = 0;

    while (i < argc)
    {
        // Verifica se há erros de escrita antes de converter
        if (writing_errors(argv[i]))
        {
            printf("Error of syntax!\n");
            free_stack(stack);
            return;
        }

        // Converte o argumento para número e verifica se está dentro dos limites
        number = ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
        {
            printf("Error, the number is outside of Integer limits!\n");
            free_stack(stack);
            return;
        }

        // Verifica se o número já está na stack
        if (duplicate(*stack, (int)number))
        {
            printf("Error, duplicated numbers!\n");
            free_stack(stack);
            return;
        }

        // Cria um novo node
        node = malloc(sizeof(r_list));
        if (!node)
        {
            printf("Malloc failed\n");
            free_stack(stack);
            return;
        }
        node->number = (int)number;
        node->next = NULL;
        if (!(*stack)) 
        {
            node->prev = NULL;
            *stack = node;
        }
        else
        {
            temp = *stack;
            while (temp->next)
                temp = temp->next;
            temp->next = node;
            node->prev = temp;
        }
        i++;
    }   
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
void sort_five(r_list **a_stack, r_list **b_stack)
{
    r_list *highest_number_b;
    r_list *highest_number_a;
    r_list *lowest_number_a;
    int lst_size;

    if(!(*a_stack) || !(*a_stack)->next)
        return ;

    lst_size = ft_lstsize((t_list *)*a_stack);
    while(lst_size > 3)
    {
        pb(a_stack, b_stack);
        lst_size--;
    }
    sort_three(a_stack);
    highest_number_a = high_number(*a_stack);
    lowest_number_a = low_number(*a_stack);
    highest_number_b = high_number(*b_stack);


    while(*b_stack)
    {
        if(*b_stack && highest_number_b && (*b_stack)->number != highest_number_b->number)
        {
            if((*b_stack)->number < lowest_number_a->number)
                pa(b_stack, a_stack);
            else if((*b_stack)->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
            else if((*b_stack)->number > lowest_number_a->number &&  (*b_stack)->number > highest_number_a->prev-> number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if((*b_stack)->number > lowest_number_a->number &&  (*b_stack)-> number < highest_number_a->prev->number)
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }

        if(*b_stack && highest_number_b && (*b_stack)->number == highest_number_b->number)
        {
            if(highest_number_b->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
            }
            else if(highest_number_b->number < lowest_number_a->number)
            {
                pa(b_stack, a_stack);
                lowest_number_a = low_number(*a_stack);
            }
            else if(highest_number_b->number > lowest_number_a->number && highest_number_b->number > highest_number_a->prev->number)
            {
                rra(a_stack);
                pa(b_stack, a_stack);
                ra(a_stack);
                ra(a_stack);
            }
            else if((*b_stack)->number < highest_number_a ->number && (*b_stack)->number > lowest_number_a->number && (*b_stack)->number < highest_number_a->prev->number && (*b_stack)->number > (*a_stack)->next->number)
            {
                ra(a_stack);
                pa(b_stack, a_stack);
                sa(a_stack);
                rra(a_stack);
            }
            else if(highest_number_b->number < highest_number_a->number && highest_number_b->number > lowest_number_a->number && highest_number_b->number < lowest_number_a->next->number)
            {
                pa(b_stack, a_stack);
                sa(a_stack);
            }
        }

        if(*b_stack && highest_number_b->number == lowest_number_a->number)
        {
            pa(b_stack, a_stack);
            lowest_number_a = low_number(*a_stack);
        }
    }
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

    init_stack(&a_stack, argv, argc);
    size = ft_lstsize((t_list *)a_stack);

    printf("a_stack antes de ordenar: ");
    r_list *temp_itera = a_stack; // Create a separate variable for iteration
    while (temp_itera)
    {
        printf("%d ", temp_itera->number);
        temp_itera = temp_itera->next;
    }
    printf("\n");
    if (verify(a_stack) == 1)
    {
        if (size == 2)
            sa(&a_stack);
        else if (size == 3)
            sort_three(&a_stack);
        else if (size == 5)
            sort_five(&a_stack, &b_stack);
    }

    // Imprimir a pilha 'a_stack'
    printf("a_stack depois de ordenar: ");
    r_list *temp_iter = a_stack; // Create a separate variable for iteration
    while (temp_iter)
    {
        printf("%d ", temp_iter->number);
        temp_iter = temp_iter->next;
    }
    printf("\n");

    if (split_argv)
        free_split(split_argv);

    free_stack(&a_stack);
    free_stack(&b_stack);
    return 0;
}