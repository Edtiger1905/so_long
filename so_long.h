#include <unistd.h>
#include <stdio.h>
#include "ft_libft/includes/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"

typedef struct s_game{
	
	int map_height;
	int map_width;
	int win_height;
	int win_width;	
}	t_game;

typedef struct s_map
{
	int rows;
	int column;
	char **matrix;
	int	*img_width;
	int	*img_height;
}	t_map;



/* DICHIARAZIONE FUNZIONI */

/* main.c: */
int main(int argc, char **argv);

/* init.c: */
void    init_game(t_game *game, t_map *map);

/* parsing_map.c: */
int validate_map(t_map *map, char *file);
int read_matrix(t_map *map, void *mlx, void *win);


/* init_map.c: */
int init_map(t_map *map, char *file);
int init_matrix(t_map *map, char *file);