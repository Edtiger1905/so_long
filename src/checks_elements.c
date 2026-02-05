#include "../includes/so_long.h"

static void count_element(t_map *map, int i, int j)
{
    if(map->matrix[i][j] == 'P')
    {
        map->player_count++;
        map->player_y = i;
        map->player_x = j;
    }
    else if(map->matrix[i][j] == 'E')
        map->exit_count++;
    else if(map->matrix[i][j] == 'C')
        map->coin++;
}
static int check_invalid_char(t_map *map, int i, int j)
{
    char c;

    c = map->matrix[i][j];
    if(c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
    {
        ft_printf("Error: Invalid character '%c' in map\n", c);
        return(0);
    }
    return(1);
}
static int validate_counts(t_map *map)
{
    if(map->player_count != 1)
    {
        ft_printf("Error: Map must have exactly 1 player/n");
        return (0);
    }
    if(map->exit_count != 1)
    {
        ft_printf("Error: Map must have exactly 1 exit/n");
        return (0);
    }
    if(map->coin < 1)
    {
        ft_printf("Error: Map must have at least 1 collectible/n");
        return (0);
    }
    return (1);
}
int validate_elements(t_map *map)
{
    int i;
    int j;

    map->player_count = 0;
    map->exit_count = 0;
    map->coin = 0;
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->column)
        {
            if(!check_invalid_char(map, i, j))
                return(0);
            count_element(map, i, j);
            j++;
        }
        i++;
    }
    return(validate_counts(map));
}
int checks(t_map *map, char *filename)
{
    if(!map_extension_is_valid(filename, ".ber"))
        return(0);
    if(!is_rectangular(map))
        return(0);
    if(!is_surrounded_by_walls(map))
        return(0);
    if(!validate_elements(map))
        return(0);
    return(1);
}