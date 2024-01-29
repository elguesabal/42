#include "../push_swap.h"

void	sa(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_second(a);
		insert_first(a, remove->n);
		free(remove);
	}
}

void	sb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_second(b);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	ss(Stack **a, Stack **b)
{
	sa(a);
	sb(b);
}

void	pa(Stack **a, Stack **b)
{
	Stack	*remove;

	if(*b)
	{
		remove = remove_first(b);
		insert_first(a, remove->n);
		free(remove);
	}
}
