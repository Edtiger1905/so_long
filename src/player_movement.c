
#include "../includes/so_long.h"

void check_coin(t_map *game, int x, int y)
{
    if(game->matrix[x][y] == 'C')
    {
        game->coin--;
        game->matrix[x][y] = '0';
    }
}

int check_exit(t_map *game, t_map *map, int x, int y)
{
    if(game->coin == 0)
    {
        exit_game(game, map->mlx);
        return (0);
    }
    return (1);
}
void move_player(t_map *game, int p_x, int p_y)
{
    int new_x;
    int new_y;

    new_x = pos_x + p_x;
    new_y = pos_y + p_y;

    if(new_x >= 0 && new_x < game->rows && new_y >= 0 && new_y < game->column 
        && game->matrix[new_x][new_y] != '1')
    {
        check_coin(game, new_x, new_y);
    }
}

int key_hook(int keycode, t_map *game, t_map *map)
{
    if(keycode ==  65363 || keycode == 100)
        mov_player(game, 1, 0);
    else if(keycode == 65361 || keycode == 97)
        mov_player(game, -1, 0);
    else if(keycode == 65362 || keycode == 119)
        move_player(game, 0 -1);
    else if(keycode == 65364 || keycode == 115)
        move_player(game, 0, 1);
    else if(keycode == 65307)
    {   
        exit_game(game, map->mlx);
        exit(0);
    }
    return (0);
}





void    player_hook(t_map *map, t_map *game)
{
    mlx_hook(map->mlx_win, 02, 1L << 0, key_hook, game);
}