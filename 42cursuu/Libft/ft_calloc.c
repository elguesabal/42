

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t n_elements, size_t size)
{
	unsigned char	*ptr;
	int	i;

	ptr = malloc(n_elements * size);
	if (ptr)
	{
		i = 0;
		while (i < n_elements * size) // PQ I VAI ATE n_elements * size E NAO ATE n_elements?
		{
			ptr[i] = 0;
			i++;
		}
		// ptr[0] = 1;
		// ptr[1] = 0;
		// ptr[2] = 0;
		// ptr[3] = 0;
	}
	return (ptr);
}

int	main(void)
{
	int	*n;

	n = ft_calloc(1, sizeof(int));
n[0] = 1;
n[1] = 0;
n[2] = 0;
n[3] = 0;

	printf("n: %d", *n);
	return (0);
}
