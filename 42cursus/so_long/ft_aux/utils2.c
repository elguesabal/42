#include "../so_long.h"

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

int	error(char *str)
{
	perror(str);
	free_map();
	return (1);
}

void	free_map(void)
{
	int	i;

	i = 0;
	while (MAP[i] || COPY_MAP[i])
	{
		if (MAP && MAP[i])
			free(MAP[i]);
		if (COPY_MAP && COPY_MAP[i])
			free(COPY_MAP[i]);
		i++;
	}
	if (MAP)
		free(MAP);
	if (COPY_MAP)
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