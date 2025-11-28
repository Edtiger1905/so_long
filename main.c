#include "minilibx-linux/mlx.h"
#include <stdio.h>

int main(void)
{
    void	*mlx;
    void    *mlx_win;
    void	*img;
    int		win_width;
    int		win_height;
    int     i;
    int     img_width;
    int     img_height;

    win_width = 1920;
    win_height = 1080;
    img_height = 32;
    img_width = 32;
    i = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, win_width, win_height, "so_long");
    while(i < (win_width / img_width))
    {
        img = mlx_xpm_file_to_image(mlx, "New-Piskel.xpm", (&img_width * i), &img_height);
        i++;
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