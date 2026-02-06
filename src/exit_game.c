#include "../includes/so_long.h"

int free_matrix(t_map *map)
{
    int i;

    if(map && map->matrix)
    {
        i = 0;
        while(i < map->rows)
        {
            if(map->matrix[i])
                free(map->matrix[i]);
            i++;
        }
        free(map->matrix);
        map->matrix = NULL;
    }
    return (0);
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

void exit_game(t_map *map, void *mlx)
{
    free_matrix(map);
    cleanup_images(map, mlx);
}
