#include "../push_swap.h"

void	rra(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_last(a);
		insert_first(a, remove->n);
		free(remove);
	}
}

void	rrb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_last(b);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	rrr(Stack **a, Stack **b)
{
	rra(a);
	rrb(b);
}