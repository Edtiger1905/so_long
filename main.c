#include "minilibx-linux/mlx.h"
#include <stdio.h>

int main(void)
{
    void	*mlx;
    void    *mlx_win;
    void	*img;
    int		win_width;
    int		win_height;
    int     	i;
    int		j;
    int     img_width;
    int     img_height;

    win_width = 640;
    win_height = 320;
    img_height = 32;
    img_width = 32;
    i = 0;
    j = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, win_width, win_height, "so_long");
    while(j < (win_height / img_height))
    {
	i = 0;
    	while(i < (win_width / img_width))
    	{
        	img = mlx_xpm_file_to_image(mlx, "New-Piskel.xpm", &img_width , &img_height);
    		if (img == NULL)
    		{
        		printf("Errore: impossibile caricare bkg.xpm\n");
        		return (1);
    		}
    		mlx_put_image_to_window(mlx, mlx_win, img, img_width * i, img_height * j);
		i++;
    	}
	j++;
    }
    mlx_loop(mlx);

    return (0);
}
