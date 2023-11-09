

#include "get_next_line.h"
#include <stdio.h>

// static int	count_line()
// {

// }

static void	get_line(int fd, char *line)
{
	//static int	i = 0;
	char	c;
	int	i;

	i = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			line[i] = '\n';
			return ;
		}
		if (c == '\0')
		{
			line[i] = '\0';
			return ;
		}
		line[i] = c;
		i++;
	}
}

char	*get_next_line(int fd)
{
	// static int	line = 0;	// SO FUNCIONA CORRETAMENTE SE A VARIAVEL FOR ATRIBUIDA JUNTO COM SUA DECLARACAO
	char		*line;
	// ssize_t		buffer_len;

	// line++;
	line = malloc(100 * sizeof(char));
	if (!line)
		return (NULL);
	// buffer_len = get_line(fd, line);
	// if (buffer_len == -1)
	// 	return (NULL);
	get_line(fd, line);
	return (line);
}