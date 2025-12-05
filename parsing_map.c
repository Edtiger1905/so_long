#include "minilibx-linux/mlx.h"
#include "so_long.h"

int read_matrix(t_map *map, void *mlx, void *win)
{
    int i;
    int j;
    void *muro;
    void *terreno;

    if (!mlx || !win)
        return (0);
    muro = mlx_xpm_file_to_image(mlx, "muro.xpm",
                                 &map->img_width, &map->img_height);
    terreno = mlx_xpm_file_to_image(mlx, "terreno.xpm",
                                    &map->img_width, &map->img_height);
    if (!muro || !terreno)
        return (0);
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            if (map->matrix[i][j] == '1')
            {
                mlx_put_image_to_window(mlx, win, muro,
                                        j * map->img_width,
                                        i * map->img_height);
            }
            else if (map->matrix[i][j] == '0')
            {
                mlx_put_image_to_window(mlx, win, terreno,
                                        j * map->img_width,
                                        i * map->img_height);
            }
            j++;
        }
        i++;
    }
    mlx_destroy_image(mlx, muro);
    mlx_destroy_image(mlx, terreno);
    
    return (1);
}
