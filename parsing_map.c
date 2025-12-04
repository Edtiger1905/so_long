#include "minilibx-linux/mlx.h"
#include "so_long.h"

/* int validate_map(t_map *map)
{
    void *mlx;
    void *terreno;
    void *muro;
    int i;
    int j;

    mlx = mlx_init();
    if (!mlx)
        return (0);
    terreno = mlx_xpm_file_to_image(mlx, "terreno.xpm", map->img_width, map->img_height);
    muro = mlx_xpm_file_to_image(mlx, "muro.xpm", map->img_width, map->img_height);
    return (1);
} */

int read_matrix(t_map *map, void *mlx, void *win)
{
    int i;
    int j;
    void *muro;
    void *terreno;

    if (!mlx)
        return (0);
    muro = mlx_xpm_file_to_image(mlx, "muro.xpm", map->img_width, map->img_height);

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            if(map->matrix[i][j] == '1')
            {
                muro = mlx_xpm_file_to_image(mlx, "muro.xpm", map->img_width, map->img_height);
                mlx_put_image_to_window(mlx, win, muro, j * (*map->img_width), i * (*map->img_height));
            }else if (map->matrix[i][j] == '0')
            {
                terreno = mlx_xpm_file_to_image(mlx, "terreno.xpm", map->img_width, map->img_height);
                mlx_put_image_to_window(mlx, win, terreno, j * (*map->img_width), i * (*map->img_height));
            }
            
            j++;
        }
        i++;
    }
    return (1);
}