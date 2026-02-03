#include "../includes/so_long.h"


void init_struct(t_map *map, t_game *game)
{
    map->matrix = NULL;
    map->img_wall = NULL;
    map->img_floor = NULL;
    map->img_exit = NULL;
    map->img_player = NULL;
    map->img_collectibles = NULL;
    map->mlx = NULL;
    map->mlx_win = NULL;
}
int main(int argc, char **argv)
{
    t_map   map;
    t_game  game;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }
    init_struct(&map, &game);
    // Prima leggi le dimensioni della mappa
    if (!init_map(&map, argv[1]))
    {
        ft_printf("Error: Failed to initialize map\n");
        return (1);
    }
    
    // Poi crea la matrice
    if (!init_matrix(&map, argv[1]))
    {
        ft_printf("Error: Failed to create matrix\n");
        return (1);
    }
    
    // Inizializza MLX PRIMA di calcolare le dimensioni
    map.mlx = mlx_init();
    if (!map.mlx)
    {
        ft_printf("Error: Failed to initialize MLX\n");
        return (1);
    }
    
    // Carica una singola immagine per ottenere le dimensioni reali
    map.img_wall = mlx_xpm_file_to_image(map.mlx, "./img/wall.xpm", 
                                          &map.img_width, &map.img_height);
    if (!map.img_wall)
    {
        ft_printf("Error: Failed to load wall.xpm\n");
        return (1);
    }
    
    // Ora calcola le dimensioni della finestra
    init_game(&game, &map);
    map.game = &game;
    
    ft_printf("Window dimensions: %dx%d\n", game.win_width, game.win_height);
    

    // Crea la finestra con le dimensioni corrette
    map.mlx_win = mlx_new_window(map.mlx, game.win_width, game.win_height, "so_long");
    if (!map.mlx_win)
    {
        exit_game(&map, "Error: Failed to create window\n");
        cleanup_images(&map, map.mlx);
        return (1);
    }
    
    // Ora carica e disegna tutto
    if (!read_matrix(&map, map.mlx, map.mlx_win))
    {
        ft_printf("Error: Failed to read matrix\n");
        cleanup_images(&map, map.mlx);
        return (1);
    }

    mlx_loop(map.mlx);
    return (0);
}
