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

// void	copy_map(char **map)
// {
// 	int	j;
// 	int	i;

// 	j = 0;
// 	i = 0;
// 	while (MAP[j][i])
// 	{
// 		while (MAP[j][i])
// 		{
// 			map[j][i] = MAP[j][i];
// 			i++;
// 			// if (MAP[j][i] == '\0')
// 			// 	map[j][i] = MAP[j][i];
// 			map[j][i] = MAP[j][i];
// 		}
// 		i = 0;
// 		j++;
// 		// if (MAP[j][i] == '\0')
// 		// 	map[j][i] = MAP[j][i];
// 		map[j][i] = MAP[j][i];
// 	}
// }