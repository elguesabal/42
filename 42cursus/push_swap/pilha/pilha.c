#include <stdio.h>

typedef struct {
	int	teste1;
	int	teste2;
} teste;

int	main(void)
{
	teste n;

	n.teste1 = 10;
	n.teste2 = 20;

	printf("%d\t%d", n.teste1, n.teste2);
}