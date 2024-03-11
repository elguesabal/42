#include <stdio.h>

void	teste(int *n)
{
	*n = 50;
}

int	main(void)
{
	int	n[] = { 10, 20, 30 };

	printf("n[0]: %d\tn[1]: %d\tn[2]: %d\n", n[0], n[1], n[2]);

	teste(&n[1]);

	printf("n[0]: %d\tn[1]: %d\tn[2]: %d\n", n[0], n[1], n[2]);

	return (0);
}