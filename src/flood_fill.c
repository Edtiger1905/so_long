#include "../includes/so_long.h"

void flood_fill(char **matrix, int x, int y, t_map *map)
{
    if(y < 0 || y >= map->rows || x < 0 || x >= map->column)
        return ;
    if(matrix[x][y] == '1' || matrix[x][y] == 'F')
        return ;
    if (matrix[x][y] == 'E')
    {
        matrix[x][y] = 'F';
        return ;
    }
    
    matrix[x][y] = 'F';
    flood_fill(matrix, x + 1, y, map);
    flood_fill(matrix, x - 1, y, map);
    flood_fill(matrix, x, y + 1, map);
    flood_fill(matrix, x, y - 1, map);
}
static int validate_flood_fill(char **matrix, t_map *map)
{
    int i;
    int j;

    i = 0;
    while(i < map->rows)
    {
        j = 0;
        while(j < map->column)
        {
            if(matrix[i][j] == 'E' || matrix[i][j] == 'C')
            {
                ft_printf("Error: Unreachable elements\n");
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

static char **create_matrix_copy(t_map *map)
{
    char **matrix_copy;
    int i;

    matrix_copy = ft_calloc(map->rows + 1, sizeof(char *));
    if(!matrix_copy)
        return (NULL);
    i = 0;
    while(i < map->rows)
    {
        matrix_copy[i] = ft_strdup(map->matrix[i]);
        if(!matrix_copy[i])
        {
            while (i > 0)
                free(matrix_copy[i--]);
            free(matrix_copy);
            return(NULL);
        }
        i++;
    }
    matrix_copy[i] = NULL;
    return(matrix_copy);
}
static void free_matrix_copy(char **matrix, int rows)
{
    int i;

    i = 0;
    while (i < rows)
        free(matrix[i++]);
    free(matrix);
}

int flood_fill_execution(t_map *map)
{
    int result;
    char **matrix_copy;

    matrix_copy = create_matrix_copy(map);
    if(!matrix_copy)
    {
        ft_printf("Error: Flood fill allocation failed\n");
        return(0);
    }
    flood_fill(matrix_copy, map->player_y, map->player_x, map);
    result = validate_flood_fill(matrix_copy, map);
    free_matrix_copy(matrix_copy, map->rows);
    return(result);
}
