#include <mlx.h>
#include <stdio.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Minha Janela");

    printf("teste");
}