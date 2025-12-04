#include "so_long.h"

int main(int argc, char **argv)
{
    void	*mlx;
    void    *mlx_win;
    t_map   map;
    t_game  game;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }
    mlx = mlx_init();
    init_game(&game, &map);
    init_map(&map, argv[1]);
    mlx_win = mlx_new_window(mlx, game.win_width, game.win_height, "so_long");
    read_matrix(&map, mlx, mlx_win);
    mlx_loop(mlx);

    return (0);
}


