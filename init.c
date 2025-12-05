#include "so_long.h"

void    init_game(t_game *game, t_map *map)
{
    game->win_width = (map->column * map->img_width) + 1;
    game->win_height = (map->rows * map->img_height) + 1;
    game->map_width = map->column;
    game->map_height = map->rows;
}