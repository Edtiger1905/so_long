
#include "../includes/so_long.h"

static void check_coin(t_map *map, int new_y, int new_x)
{
    if(map->matrix[new_y][new_x] == 'C')
    {
        map->coin--;
        map->matrix[new_y][new_x] = '0';
        ft_printf("Collectibles: %d\n", map->coin);
    }
}

static int check_exit(t_map *map, int new_y, int new_x)
{
    if(map->matrix[new_y][new_x] == 'E')
    {
        if(map->coin == 0)
        {
            ft_printf("YOU WIN! Moves: %d\n", map->moves);
            exit_game(map, map-> mlx);
            exit(0);
        }
        else
        {
            ft_printf("Collect all items! (%d left)\n", map->coin);
            return(0);
        }
    }
    return(1);
}

static int is_valid_move(t_map *map, int new_y, int new_x)
{
    if(new_y < 0 || new_y >= map->rows)
        return(0);
    if(new_x < 0 || new_x >= map->column)
        return(0);
    if(!check_exit(map, new_y, new_x))
        return(0);
    return(1);
}
void move_player(t_map *map, int dy, int dx)
{
    int new_x;
    int new_y;

    new_y = map->p_y + dy;
    new_x = map->p_x + dx;
    if(!is_valid_move(map, new_y, new_x))
        return ;
    map->matrix[map->p_y][map->p_x] = '0';
    check_coin(map, new_y, new_x);
    map->p_y = new_y;
    map->p_x = new_x;
    map->matrix[new_y][new_x] = 'P';
    map->moves++;
    ft_printf("Moves: %d\n", map->moves);
    redraw_map(map);
}

int key_hook(int keycode, t_map *map)
{
    if(keycode == 65307)
    {   
        exit_game(map, map->mlx);
        exit(0);
    }
    else if(keycode ==  65363 || keycode == 100)
        mov_player(map, 0, 1);
    else if(keycode == 65361 || keycode == 97)
        mov_player(map, 0, -1);
    else if(keycode == 65362 || keycode == 119)
        move_player(map, -1, 0);
    else if(keycode == 65364 || keycode == 115)
        move_player(map, 1, 0);
    return (0);
}
