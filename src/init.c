#include "../includes/so_long.h"

void init_game(t_game *game, t_map *map)
{
    // Le dimensioni dell'immagine devono essere già state caricate
    game->win_width = map->column * map->img_width;
    game->win_height = map->rows * map->img_height;
    game->map_width = map->column;
    game->map_height = map->rows;
}