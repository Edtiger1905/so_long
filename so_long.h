#include <unistd.h>
#include "ft_libft/includes/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_game{
	
	int map_height;
	int map_width;	
}	t_game;

typedef struct s_map
{
	int rows;
	int column;
	char **matrix;
}	t_map;
