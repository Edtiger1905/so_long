
#include "../includes/so_long.h"

static void put_image(t_map *map, void *img, int x, int y)
{
    mlx_put_image_to_window(map->mlx, map->mlx_win, img,
        x * map->img_width, y * map->img_height);
}
static void render_tile(t_map *map, int i, int j)
{
    char tile;

    put_image(map, map->img_floor, j, i);
    tile = map->matrix[i][j];
    if(tile == '1')
        put_image(map, map->img_wall, j, i);
    else if(tile == 'E')
        put_image(map, map->img_exit, j, i);
    else if(tile == 'C')
        put_image(map, map->img_collectibles, j, i);
    else if(tile == 'P')
        put_image(map, map->img_player, j, i);
}

void redraw_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    while(i < map->rows)
    {
        j = 0;
        while(j < map->column)
        {
            render_tile(map, i, j);
            j++;
        }
        i++;
    }
}

int read_matrix(t_map *map, void *mlx, void *win)
{
    if(!mlx || !win || !map || !map->matrix)
        return(0);
    if(!map->img_wall || !map->img_floor || !map->img_exit)
        return(0);
    if(!map->img_player || !map->img_collectibles)
        return(0);
    redraw_map(map);
    return(1);
}