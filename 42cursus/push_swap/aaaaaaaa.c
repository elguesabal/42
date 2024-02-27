// ??
int	count_max_of_bits(int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb >> 1;
	}
	return (count);
}

// ??
int	index_max(t_stk *stake)
{
	t_stk	*temp;
	int		max;

	max = -1;
	temp = stake;
	while (temp)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

// FUNCAO Q ORGANIZA CASO TENHA 3 NUMEROS
void	sort_tree(t_stk **stack_a)
{
	if (((*stack_a)->next->x > (*stack_a)->x)
		&& ((*stack_a)->next->x > (*stack_a)->next->next->x))
		rra(stack_a);
	if (((*stack_a)->x > (*stack_a)->next->x)
		&& ((*stack_a)->x > (*stack_a)->next->next->x))
		ra(stack_a);
	if ((*stack_a)->x > (*stack_a)->next->x
		&& (*stack_a)->x < (*stack_a)->next->next->x)
		sa(stack_a);
}

// FUNCAO Q ORGANIZA CASO TENHA 4 NUMEROS
void	sort_four(t_stk **stack_a, t_stk **stack_b)
{
	int		count;
	t_stk	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b);
	sort_tree(stack_a);
	pa(stack_b, stack_a);
}

// FUNCAO Q ORGANIZA CASO TENHA 5 NUMEROS
void	sort_five(t_stk **stack_a, t_stk **stack_b)
{
	int		count;
	t_stk	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}

// FUNCAO Q ORGANIZA CASO TENHA MAIS DE 6 NUMEROS
void	radix_sort(t_stk **stack_a, t_stk **stack_b)
{
	int		max_bits;
	int		i;
	int		size_list;

	i = 0;
	max_bits = count_max_of_bits(index_max(*stack_a));
	while (i < max_bits)
	{
		size_list = list_size(*stack_a);
		while (size_list)
		{
			if ((((*stack_a)->index >> i) & 0b0000001) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size_list--;
		}
		while (*stack_b != NULL)
			pa(stack_b, stack_a);
		i++;
	}
}

// ALGORITIMO FINAL QUE ORGANIZA OS NUMEROS
void	sort_list(t_stk **stack_a, t_stk **stack_b)
{
	if (check_list_sorted(*stack_a)) // ACHO Q EU JA TENHO UMA FUNCAO Q VERIFICA SE TA ORDENADO
		return ;
	if (list_size(*stack_a) == 2)
		sa(stack_a);
	else if (list_size(*stack_a) == 3)
		sort_tree(stack_a);
	else if (list_size(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (list_size(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}















// FUNCAO Q GRAVA NA VARIAVEL index DE CADA NO A POSICAO Q CADA NO DEVERIA ESTAR
void	index_list(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*small;
	int		i;
	int		size_list;
	int		nb;

	i = 0;
	size_list = list_size(stack);
	while (i < size_list)
	{
		nb = 2147483647;
		temp = stack;
		while (temp)
		{
			if (nb >= temp->x && temp->index == -1)
			{
				small = temp;
				nb = temp->x;
			}
			temp = temp->next;
		}
		small->index = i;
		i++;
	}
}