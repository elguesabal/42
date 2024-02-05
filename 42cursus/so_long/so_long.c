#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	width;
	int	height;
} width_height;

void draw_background(void *mlx_ptr, void *win_ptr, char *image_path, int width, int height)
{
    void	*img_ptr;
    int		img_width;
	int		img_height;

    // CARREGA A IMAGEM
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_width, &img_height);

    // DESENHA A IMAGEM NA JANELA
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, width, height);
}

int    ft_key(int key, void *param)
{
	width_height	*gojo = (width_height *)param;

	if(key == 'w')
	{
		gojo->width -= 100;
		draw_background(gojo->mlx_ptr, gojo->win_ptr, "image.xmp", gojo->width, gojo->height);
		printf("w\n");
	}
	else if(key == 'a')
	{
		gojo->height -= 100;
		draw_background(gojo->mlx_ptr, gojo->win_ptr, "image.xmp", gojo->width, gojo->height);
		printf("a\n");
	}
	else if(key == 's')
	{
		gojo->width += 100;
		// printf("%d\n", gojo->width);
		draw_background(&gojo->mlx_ptr, &gojo->win_ptr, "image.xmp", gojo->width, gojo->height);	// TENDI NADA
		// printf("s\n");
	}
	else if(key == 'd')
	{
		gojo->height += 100;
		draw_background(gojo->mlx_ptr, gojo->win_ptr, "image.xmp", gojo->width, gojo->height);
		printf("d\n");
	}
	else if(key == 65307)	// ESC
	{
		// mlx_destroy_window((void *)param);
		printf("ESC\n");
	}


	// printf("%c\n", key);
}

int close_window(void *mlx_ptr, void *win_ptr)
{
    // Sair do loop de eventos
    mlx_destroy_window(mlx_ptr, win_ptr);
    return (0);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
	width_height	location;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Minha janela");

	location.mlx_ptr = mlx_ptr;
	location.win_ptr = win_ptr;
	location.width = 0;
	location.height = 0;

	mlx_key_hook(win_ptr, ft_key, &location);
	mlx_hook(win_ptr, 17, 0, close_window, win_ptr);



// sleep(1);
// // location.width = 10;
// // location.height = 20;
// // printf("%d\n", location.width);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 0, 0);
// sleep(1);
// 	mlx_clear_window(mlx_ptr, win_ptr);
// sleep(1);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 400, 0);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 200, 100);
// sleep(1);
// 	mlx_clear_window(mlx_ptr, win_ptr);



    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
}