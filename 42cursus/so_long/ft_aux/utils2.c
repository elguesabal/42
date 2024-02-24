#include "../so_long.h"

void	*allocate_memory(int map_j, int map_i)
{
	char	**memory;
	int		i;

	memory = (char **)ft_calloc(map_j, sizeof(char *));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < 100)
	{
		memory[i] = (char *)ft_calloc(map_i, sizeof(char));
		if (memory[i] == NULL)
			return (NULL);
		i++;
	}
	return (memory);
}

void	free_map()
{
	int	i;

	i = 0;
	while (MAP[i])
	{
		free(MAP[i]);
		free(COPY_MAP[i]);
		i++;
	}
	free(MAP);
	free(COPY_MAP);
}
