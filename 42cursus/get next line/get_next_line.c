

#include "get_next_line.h"
#include <stdio.h>

static void	get_line(int fd, char *buffer)
{
	static int	i = 0;

	i += 100;
	read(fd, buffer, 100);
}

char	*get_next_line(int fd)
{
	// static int	line = 0;	// SO FUNCIONA CORRETAMENTE SE A VARIAVEL FOR ATRIBUIDA JUNTO COM SUA DECLARACAO
	char		*buffer;
	ssize_t		buffer_len;

	line++;
	buffer = malloc(100 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer_len = read(fd, buffer, 100);
	if (buffer_len == -1)
		return (NULL);
	return (buffer);
}