#include "so_long.h"

void    init_game(t_game *game, t_map *map)
{
    game->win_height = 320;
    game->win_width = 640;

    *map->img_width = 32;
    *map->img_height = 32;


}