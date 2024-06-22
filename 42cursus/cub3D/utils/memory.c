#include "./../cub3D.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	char	*ptr;
	size_t	i;

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

void	*allocate_memory(int x, int y)
{
	char	**memory;
	int		i;

	memory = ft_calloc(x, sizeof(char *));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		memory[i] = ft_calloc(y, sizeof(char));
		if (memory[i] == NULL)
			return (NULL);
		i++;
	}
	return (memory);
}
