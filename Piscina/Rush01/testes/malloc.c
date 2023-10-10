#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int	i;
	int	j;
	int	**mat;

	mat = malloc(4 * sizeof(int*));

	i = 0;
	while (i < 4)
	{
		mat[i] = malloc(4 * sizeof(int));
		i++;
	}

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}













	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}





}
