#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("ERRO");
		return (1);
	}
	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd);
		//printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}