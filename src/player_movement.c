
#include "../includes/so_long.h"


int key_hook(int keycode, t_map *game)
{
    if(keycode ==  65363 || keycode == 100)
        mov_pg;
    else if(keycode == 65361 || keycode == 97)
        mov_pg;
    else if(keycode == 65362 || keycode == 119 )
        move_pg;
    else if(keycode == 65364 || keycode == 115)
        move_pg;
    else if(keycode == 65307)
    {   
        exit_game(game, );
        exit(0);
    }
    return (0);
}





void    player_hook(t_map *map, t_map *game)
{
    mlx_hook(map->mlx_win, 02, 1L << 0, key_hook, game);
}