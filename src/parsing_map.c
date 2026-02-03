#include "../includes/so_long.h"

int read_matrix(t_map *map, void *mlx, void *win)
{
    int i;
    int j;

    if (!mlx || !win || !map || !map->matrix)
        return (0);

    /* carica SOLO se non già caricate */
    if (!map->img_wall)
        map->img_wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm",
                                &map->img_width, &map->img_height);
    if (!map->img_floor)
        map->img_floor = mlx_xpm_file_to_image(mlx, "./img/floor.xpm",
                                &map->img_width, &map->img_height);
    if (!map->img_exit)
        map->img_exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm",
                                &map->img_width, &map->img_height);
    if (!map->img_player)
        map->img_player = mlx_xpm_file_to_image(mlx, "./img/testcp.xpm",
                                &map->img_width, &map->img_height);
    if (!map->img_collectibles)
        map->img_collectibles = mlx_xpm_file_to_image(mlx, "./img/collectibles.xpm",
                                &map->img_width, &map->img_height);

    if (!map->img_wall || !map->img_floor || !map->img_exit ||
        !map->img_player || !map->img_collectibles)
        return (0);

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            if (map->matrix[i][j] == '1')
                mlx_put_image_to_window(mlx, win, map->img_wall,
                        j * map->img_width, i * map->img_height);
            else if (map->matrix[i][j] == '0')
                mlx_put_image_to_window(mlx, win, map->img_floor,
                        j * map->img_width, i * map->img_height);
            else if (map->matrix[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, map->img_exit,
                        j * map->img_width, i * map->img_height);
            else if (map->matrix[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, map->img_collectibles,
                        j * map->img_width, i * map->img_height);
            else if (map->matrix[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, map->img_player,
                        j * map->img_width, i * map->img_height);
            j++;
        }
        i++;
    }
    return (1);
}

void cleanup_images(t_map *map, void *mlx)
{
    if (map->img_wall)
        mlx_destroy_image(mlx, map->img_wall);
    if (map->img_floor)
        mlx_destroy_image(mlx, map->img_floor);
    if (map->img_exit)
        mlx_destroy_image(mlx, map->img_exit);
    if (map->img_player)
        mlx_destroy_image(mlx, map->img_player);
    if (map->img_collectibles)
        mlx_destroy_image(mlx, map->img_collectibles);
}


