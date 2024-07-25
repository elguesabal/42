#include "./../cub3D.h"

/// @brief FUNCAO CHAMADA A CADA CLICK NO TECLADO
/// @param key NUMERO DA TECLA PRESSIONADA
/// @param param PONTEIRO COM INFORMACOES PASSADAS
/// @return RETORNA UM STATUS PARA A FUNCAO QUE CHAMOU ESTA
int keyboard(int key, void *param)
{
	(void)param;
	if (key == 65307)
		close_win(0, NULL);
	printf("%c\n", key);
	return (0);
}
