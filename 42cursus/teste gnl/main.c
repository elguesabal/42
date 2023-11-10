#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const *argv[]) {
	int fd;
	int i;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	close(fd);
	return (argc);
}