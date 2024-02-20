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