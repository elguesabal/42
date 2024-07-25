#include "./../cub3D.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(n_elements * size);
	if (ptr)
	{
		i = 0;
		while (i < n_elements)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

/// @brief ALLOCA MEMORIA DO TAMANHO DO MAPA PASSADO E GARANTE QUE TODOS OS ESPACOS ESTARAM EM BRANCO
/// @param x NUMERO DE COLUNAS DO MAPA
/// @param y NUMERO DE LINHAS DO MAPA
/// @return RETORNA UM ENDERECO DE MEMORIA COM O TAMANHO DO MAPA
void	*allocate_memory(int x, int y)
{
	char	**memory;
	int		i;

	memory = ft_calloc(y, sizeof(char *));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		memory[i] = ft_calloc(x, sizeof(char));
		if (memory[i] == NULL)
			return (NULL);
		i++;
	}
	return (memory);
}

/// @brief LIBERA A MEMORIA ALOCADA DO MAPA **E DA COPIA**
void	free_map()
{
	int	i;

	i = 0;
	while (i < g_y + 1)
	{
		free(g_map[i]);
		free(g_copy_map[i]);
		i++;
	}
	free(g_map);
	free(g_copy_map);
}
