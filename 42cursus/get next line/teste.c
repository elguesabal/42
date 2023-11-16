#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index;
	static int	buffer_size;
	char		*line;
	int			line_size;

	line = NULL;
	line_size = 0;
	while (1)
	{
		if (buffer_index == buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			if (buffer_size == 0 && line_size > 0)
				return (line);
			buffer_index = 0;
		}
		while (buffer_index < buffer_size)
		{
			if (buffer[buffer_index] == '\n')
			{
				line = realloc(line, line_size + 1);
				line[line_size] = '\0';
				buffer_index++;
				return (line);
			}
			else
			{
				line = realloc(line, line_size + 1);
				line[line_size++] = buffer[buffer_index];
				buffer_index++;
			}
		}
	}
}

// Exemplo de uso
int main() {
    int fd = open("arquivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int i = 0;
    char *line;

    // Chama a função até que ela retorne NULL, indicando o final do arquivo
    while (i < 3) {
        line = get_next_line(fd);
        // Faça algo com a linha, por exemplo, imprimir no console
        printf("%s\n", line);
        free(line); // Não se esqueça de liberar a memória alocada para a linha
        i++;
    }

    close(fd);
    return 0;
}
