#include "./../cub3D.h"

/// @brief FUNCAO RESPONSAVEL PELO CLICK DO "X" DA JANELA (ELA TBM LIBERA TODAS AS MEMORIAS ALOCADAS)
/// @param key NUMERO DA TECLA PRESSIONADA
/// @param param PONTEIRO COM INFORMACOES PASSADAS
/// @return RETORNA UM STATUS PARA A FUNCAO QUE CHAMOU ESTA
int	close_win(int key, void *param)
{
	(void)key;
	(void)param;
	if (g_mlx && g_win)
		mlx_destroy_window(g_mlx, g_win);
	if (g_mlx)
		mlx_destroy_display(g_mlx);
	if (g_mlx)
		free(g_mlx);
	free_map();
	exit(0);
	return (0);
}