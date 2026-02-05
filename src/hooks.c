#include "../includes/so_long.h"

int close_window(t_map *map)
{
    ft_printf("Window closed\n");
    exit_game(map, map->mlx);
    exit(0);
    return(0);
}

void init_hooks(t_map *map)
{
    mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
    mlx_hook(map->mlx_win, 17, 0, close_window, map);
}