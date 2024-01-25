#include "push_swap.h"

void	insert_first(Stack **no, int n)
{
	Stack	*new;

	new = malloc(sizeof(Stack));
	if(!new)
		return ;
	new->n = n;
	new->next = *no;
	new->previous = NULL;
	if(*no)
		(*no)->previous = new;
	*no = new;
}

void	insert_second(Stack **no, int n)
{
	Stack	*new;

	if(!*no)
		insert_first(no, n);
	else
	{
		new = malloc(sizeof(Stack));
		if(!new)
			return ;
		new->n = n;
		new->next = (*no)->next;
		new->previous = *no;
		(*no)->next = new;
		(*no)->next->next->previous = new;
	}
}

void	insert_penultimate(Stack **no, int n)
{
	Stack	*new;
	Stack	*assist;

	if(!*no || !assist->next->next)
		insert_first(no, n);
	else
	{
		new = malloc(sizeof(Stack));
		if(!new)
			return ;
		assist = *no;
		while(assist->next->next)
			assist = assist->next;
		new->n = n;
		new->next = assist->next;
		new->previous = assist;
		assist->next = new;
		assist->next->next->previous = new;
	}
}

void	insert_last(Stack **no, int n)
{
	Stack	*new;
	Stack	*assist;

	new = malloc(sizeof(Stack));
	if(!new)
		return ;
	new->n = n;
	new->next = NULL;
	if(!*no)
	{
		*no = new;
		new->previous = NULL;
	}
	else
	{
		assist = *no;
		while(assist->next)
			assist = assist->next;
		assist->next = new;
		new->previous = assist;
	}
}