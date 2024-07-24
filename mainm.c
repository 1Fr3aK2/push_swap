#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct p_list
{
	int			    number;
    int             index;
	struct p_list	*next;
    struct p_list   *prev;

}					r_list;



t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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

static void reverse(r_list **stack)
{
    r_list *temp;
    r_list *lastnode;
    
    if (!(*stack) || !(*stack) -> next)
        return ;
    lastnode = (r_list *)ft_lstlast((t_list *)stack);
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
        lastnode = (r_list *)ft_lstlast((t_list *)*stack); // encontrar o ultimo node
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

void ss(r_list **a_stack, r_list **b_stack)
{
    swap(a_stack);
    swap(b_stack);
    printf("ss\n"); 
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

void add_node(r_list **stack, int number)
{
    r_list *newnode;
    r_list *lastnode;

    if (!stack)
        return ;
    newnode = malloc(sizeof(r_list));
    if (!newnode)
        return ;
    newnode->next = NULL;
    newnode->number = number;
    if (!*stack)
    {
        *stack = newnode;
        newnode->prev = NULL;
    }
    else
    {
        lastnode = (r_list *)ft_lstlast((t_list *)*stack);
        lastnode->next = newnode;
        newnode->prev = lastnode;
    }
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
				return (free_str(dest, i));
		}
		while (*s && *s != c)
			s++;
	}
	dest[i] = 0;
	return (dest);
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
            else if((*b_stack)->number > highest_number_a->number)
            {
                pa(b_stack, a_stack);
                ra(a_stack);
                highest_number_a = high_number(*a_stack);
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


void init_stack(r_list **stack, char *argv[])
{
    r_list *node;
    r_list *temp;
    long number;
    int i;

    i = 1;
    while(argv[i])
    {
        number = ft_atol(argv[i]);
        if(number > INT_MAX || number < INT_MIN)
            write(2, "Error", 5);
        node = malloc(sizeof(r_list));
        if(!node)
        {
            write(2, "Malloc failed", 13);
            return ;
        }
        node -> number = (int)number;
        node -> next = NULL;
        if(!(*stack))
        {
            node->prev = NULL;
            (*stack) = node;
        }
        else
        {
            temp = (*stack);
            while(temp -> next)
                temp = temp -> next;
            temp -> next = node;
            node -> prev = temp;
        }
        i++;
    }
}

void free_stack(r_list **stack)
{
    r_list *temp;

    if(!stack || !(*stack))
        return ;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}


int main(int argc, char *argv[])
{
    r_list *a_stack = NULL;
    r_list *b_stack = NULL;
    int size;
    
    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');

    init_stack(&a_stack, argv);
    size = ft_lstsize((t_list *)a_stack);
    if (verify(a_stack) == 1)
    {
        if (size == 2)
            sa(&a_stack);
        else if (size == 3)
            sort_three(&a_stack);
        else if (size == 5)
            sort_five(&a_stack, &b_stack);
    }

    while (a_stack)
    {
        printf("%d ", a_stack->number);
        a_stack = a_stack->next;
    }

    free_stack(&a_stack);
    free_stack(&b_stack);
    return (0);
}