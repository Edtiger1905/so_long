#include "minilibx-linux/mlx.h"
#include <stdio.h>

int main(void)
{
    void	*mlx;
    void    *mlx_win;
    void	*img;
    int		img_width;
    int		img_height;
    int     i;

    img_width = 1920;
    img_height = 1080;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, img_width, img_height, "so_long");
    while(i < img_width)
    {
        img = mlx_xpm_file_to_image(mlx, "New-Piskel.xpm", &img_width, &img_height);
        i = i + 32;
    }
    if (img == NULL)
    {
        printf("Errore: impossibile caricare bkg.xpm\n");
        return (1);
    }
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    
    mlx_loop(mlx);

    return (0);
}