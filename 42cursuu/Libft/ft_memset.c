#include <stdio.h>

void	*memset(void *str, int c, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
}

int	main(void)
{
	char	str[10];

	memset(str, '*', 10);
	printf("str: %s", str);
	return (0);
}

// DEPOIS TERMINO