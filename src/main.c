#include "../includes/so_long.h"

void init_struct(t_map *map)
{
    map->matrix = NULL;
    map->img_wall = NULL;
    map->img_floor = NULL;
    map->img_exit = NULL;
    map->img_player = NULL;
    map->img_collectibles = NULL;
    map->mlx = NULL;
    map->mlx_win = NULL;
    map->player_x = 0;
    map->player_y = 0;
    map->coin = 0;
    map->moves = 0;
    map->exit_count = 0;
    map->player_count = 0;
}


static int validate_map(t_map *map, char *file)
{
    if(!init_map(map, file))
        return (ft_printf("Error: Failed to initialize map\n"), 0);
    if(!init_matrix(map, file))
        return(ft_printf("Error: Failed to create matrix\n"), 0);
    if(!checks(map, file))
    {
        free_matrix(map);
        return(0);
    }
    if(!flood_fill_execution(map))
    {
        free_matrix(map);
        return(0);
    }
    return(1);
}

static int init_game_window(t_map *map, t_game *game)
{
    map->mlx = mlx_init();
    if(!map->mlx)
        return(ft_printf("Error: Failed to initialize MLX\n"), 0);
    if(!load_images(map))
    {
        exit_game(map, map->mlx);
        return(0);
    }
    init_game(game, map);
    map->game = game;
    map->mlx_win = mlx_new_window(map->mlx, game->win_width,
            game->win_height, "so_long");
    if(!map->mlx_win)
    {
        exit_game(map, map->mlx);
        return(ft_printf("Error: Failed to create window\n"), 0);
    }
    return(1);
}
int main(int ac, char **av)
{
    t_map map;
    t_game game;

    if(ac != 2)
        return (ft_printf("Usage: %s <map.ber>\n", av[0]), 1);
    init_struct(&map);
    if(!validate_map(&map, av[1]))
        return(1);
    if(!init_game_window(&map, &game))
        return(1);
    if(!read_matrix(&map, map.mlx, map.mlx_win))
    {
        exit_game(&map, map.mlx);
        return(ft_printf("Error: Failed to draw map\n"), 1);
    }
    init_hooks(&map);
    ft_printf("Game started! Collect %d ichigo's hollow masks to finish the game\n", map.coin);
    mlx_loop(map.mlx);
    return (0);
}
