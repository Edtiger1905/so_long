#include "so_long.h"

int read_matrix(t_map *map, void *mlx, void *win)
{
    int i;
    int j;

    if (!mlx || !win)
        return (0);
    
    write(1, &map->img_height, 1);
    write(1, &map->img_width, 1);
    // Carica le immagini e salvale nella struttura
    map->img_wall = mlx_xpm_file_to_image(mlx, "wall.xpm",
                                 &map->img_width, &map->img_height);
    map->img_floor = mlx_xpm_file_to_image(mlx, "floor.xpm",
                                    &map->img_width, &map->img_height);
    map->img_exit = mlx_xpm_file_to_image(mlx, "exit.xpm",
                                    &map->img_width, &map->img_height);
    map->img_player = mlx_xpm_file_to_image(mlx, "player.xpm",
                                    &map->img_width, &map->img_height);
    map->img_collectibles = mlx_xpm_file_to_image(mlx, "collectibles.xpm",
                                    &map->img_width, &map->img_height);

    // Controlla che tutte le immagini siano caricate
    if (!map->img_wall || !map->img_floor || !map->img_exit || 
        !map->img_player || !map->img_collectibles)
    {
        // In caso di errore, distruggi solo quelle caricate
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
        return (0);
    }
    
    // Disegna la mappa
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            write(1, &map->matrix[i][j], 1); // Debug: stampa il carattere della matrice
            if (map->matrix[i][j] == '1')
                mlx_put_image_to_window(mlx, win, map->img_wall,
                                        j * map->img_width,
                                        i * map->img_height);
            else if (map->matrix[i][j] == '0')
                mlx_put_image_to_window(mlx, win, map->img_floor,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, map->img_exit,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, map->img_collectibles,
                                        j * map->img_width,
                                        i * map->img_height);
            else if(map->matrix[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, map->img_player,
                                        j * map->img_width,
                                        i * map->img_height);
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