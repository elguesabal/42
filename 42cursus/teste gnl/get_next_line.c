#include "get_next_line.h"

/*
** Aloca memória suficiente para uma cópia da string s1, faz a cópia,
** e retorna um ponteiro para ele.
*/

static char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

/*
** Aloca com malloc() e retorna uma string “fresca” terminando com ’\0’,
** resultado da concatenação de s1 e s2. Se a alocação falhar, o
** função retorna NULL.
*/

static char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

/*
** Verifique se o que está na pilha possui uma nova linha. Se não, retorna
** um zero (0) para indicar que não é válido. Se houver uma nova linha, fazemos um
** copiamos a pilha para a linha e copiamos tudo o que estava na pilha
** antes, de volta à pilha (com a pilha temporária que criamos).
*/

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*strchr_stack;
	int				i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

/*
** Lê no heap, a partir dos descritores de arquivo, um número específico de bytes
** definido pela macro BUFF_SIZE no arquivo get_nex_line.h. Isso vai
** continue a leitura quando o valor de retorno da função de leitura for maior
** que zero (sem erros ou se não houver mais nada para ler).
** Se houver algo na pilha, concatinaremos o que estiver dentro
** ali, com tudo o que for lido na pilha. Se não, vamos apenas adicionar
** tudo o que estiver na pilha, na pilha. Então verificaremos a pilha para
** veja se há uma nova linha. Se houver, interromperemos o loop while
** e forçar o valor ret positivo para um (1), usando a macro RET_VALUE().
** Este formulário de resposta SO me ajudou a visualizar melhor a pilha e o heap:
** http://stackoverflow.com/a/1213360
*/

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (gnl_verify_line(stack, line))
			break ;
	}
	return (RET_VALUE(ret));
}

/*
** É aqui que a verdadeira merda acontece.
** Primeiro verifica se há erros (se a linha está vazia, se o número do arquivo
** descritor é inválido ou se não conseguir alocar o heap), então ele pode retornar
** menos um (-1) se necessário.
**
** Se houver algo na pilha (porque estamos usando uma variável estática),
** verificamos se há uma nova linha. Caso contrário, alocamos memória para o heap,
** e lemos o arquivo.
**
** Quando a leitura do arquivo terminar, vamos liberar o heap (não vamos
** use mais) e verificamos o valor de ret (se for 1 ou -1, retorne
** que, se a pilha estiver vazia, retorne 0). Se nenhuma destas condições for
** válido, atribuímos linha ao valor da pilha, liberamos a pilha e retornamos 1
**
** Uma boa leitura sobre descritores de arquivos:
** http://www.bottomupcs.com/file_descriptors.xhtml
*/

int					get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = gnl_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}