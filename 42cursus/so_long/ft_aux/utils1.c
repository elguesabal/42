#include "../so_long.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(n_elements * size);
	if (ptr)
	{
		i = 0;
		while (i < n_elements * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

int	size_j(void)
{
	int	count;

	count = 0;
	while (MAP[count][0])
		count++;
	return (count);
}

int	size_i(void)
{
	int	count;

	count = 0;
	while (MAP[0][count])
		count++;
	return (count);
}