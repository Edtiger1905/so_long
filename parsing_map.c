#include "so_long.h"

int read_matrix(t_map *map, void *mlx, void *win)
{
    int i;
    int j;
    void *wall;
    void *floor;
    void *exit;
    void *player;
    void *collectibles;

    if (!mlx || !win)
        return (0);
    
    wall = mlx_xpm_file_to_image(mlx, "wall.xpm",
                                 &map->img_width, &map->img_height);
    floor = mlx_xpm_file_to_image(mlx, "floor.xpm",
                                    &map->img_width, &map->img_height);
    exit = mlx_xpm_file_to_image(mlx, "exit.xpm",
                                    &map->img_width, &map->img_height);
    player = mlx_xpm_file_to_image(mlx, "player.xpm",
                                    &map->img_width, &map->img_height);
    collectibles = mlx_xpm_file_to_image(mlx, "collectibles.xpm",
                                    &map->img_width, &map->img_height);

    if (!wall || !floor || !exit || !player || !collectibles)
    {
        if (wall)
            mlx_destroy_image(mlx, wall);
        if (floor)
            mlx_destroy_image(mlx, floor);
        if (exit)
            mlx_destroy_image(mlx, exit);
        if (player)
            mlx_destroy_image(mlx, player);
        if (collectibles)
            mlx_destroy_image(mlx, collectibles);
        return (0);
    }
    
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            if (map->matrix[i][j] == '1')
                mlx_put_image_to_window(mlx, win, wall,
                                        j * map->img_width,
                                        i * map->img_height);
            else if (map->matrix[i][j] == '0')
                mlx_put_image_to_window(mlx, win, floor,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, exit,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, collectibles,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, player,
                                        j * map->img_width,
                                        i * map->img_height);
            j++;
        }
        i++;
    }
    
    // NON distruggere le immagini qui!
    // Le distruggerai solo alla fine del programma
    
    return (1);
}