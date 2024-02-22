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

void	*allocate_memory(int map_j, int map_i)
{
	char	**memory;
	int		i;

	memory = (char **)ft_calloc(map_j, sizeof(char *));
	if (memory == NULL)
	{
		perror("Error\nMemoria nao alocar memoria");
		return (NULL);
	}
	i = 0;
	while (i < 100)
	{
		memory[i] = (char *)ft_calloc(map_i, sizeof(char));
		if (memory[i] == NULL)
		{
			perror("Erro\nMemoria nao alocar memoria");
			return (NULL);
		}
		i++;
	}
	return (memory);
}

void	copy_map(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (MAP[j][i])
	{
		while (MAP[j][i])
		{
			map[j][i] = MAP[j][i];
			i++;
			// if (MAP[j][i] == '\0')
			// 	map[j][i] = MAP[j][i];
			map[j][i] = MAP[j][i];
		}
		i = 0;
		j++;
		// if (MAP[j][i] == '\0')
		// 	map[j][i] = MAP[j][i];
		map[j][i] = MAP[j][i];
	}
}