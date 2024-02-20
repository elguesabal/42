#include "../so_long.h"

// FUNCAO PARA PEGAR O NOME DA IMAGEM E POSICAO PARA RENDERIZAR A IMAGEM
void draw_background(char *image_path, int width, int height)
{
    void	*img_ptr;
    int		img_width;
	int		img_height;

    // CARREGA A IMAGEM
    img_ptr = mlx_xpm_file_to_image(MLX_PTR, image_path, &img_width, &img_height);

    // DESENHA A IMAGEM NA JANELA
    mlx_put_image_to_window(MLX_PTR, WIN_PTR, img_ptr, width, height);
}