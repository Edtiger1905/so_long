#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../ft_libft/includes/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	int	map_height;
	int	map_width;
	int	win_height;
	int	win_width;
}	t_game;

typedef struct s_map
{
	void			*mlx;
	void			*mlx_win;
	int				rows;
	int				column;
	char			**matrix;
	int				img_width;
	int				img_height;
	void			*img_wall;
	void			*img_floor;
	void			*img_exit;
	void			*img_player;
	void			*img_collectibles;
	int				player_x;
	int				player_y;
	int				coin;
	int				moves;
	int				exit_count;
	int				player_count;
	struct s_game	*game;
}	t_map;

/* init_map.c */
int		init_map(t_map *map, char *file);
int		init_matrix(t_map *map, char *file);

/* init.c */
void	init_game(t_game *game, t_map *map);
void	init_struct(t_map *map);

/* checks.c */
int		is_rectangular(t_map *map);
int		is_surrounded_by_walls(t_map *map);
int		map_extension_is_valid(char *filename, char *extension);

/* checks_elements.c */
int		validate_elements(t_map *map);
int		checks(t_map *map, char *filename);

/* flood_fill.c */
int		flood_fill_execution(t_map *map);
void	flood_fill(char **matrix, int y, int x, t_map *map);

/* render.c */
void	redraw_map(t_map *map);
int		read_matrix(t_map *map, void *mlx, void *win);

/* player_movement.c */
void	move_player(t_map *map, int dy, int dx);
int		key_hook(int keycode, t_map *map);

/* hooks.c */
int		close_window(t_map *map);
void	init_hooks(t_map *map);

/* load_images.c */
int		load_images(t_map *map);

/* exit_game.c */
void	free_matrix(t_map *map);
void	cleanup_images(t_map *map, void *mlx);
void	exit_game(t_map *map, void *mlx);

#endif