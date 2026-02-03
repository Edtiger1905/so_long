#include "./includes/so_long.h"

void free_matrix(char **matrix)
{
    int i;

    i = 0;
    while(matrix[i] != NULL)
    {
        free(matrix[i]);
        matrix[i] = NULL;
        i++;
    }
    free(matrix);
}

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
static int validate_flood_fill(char **matrix)
{
    int i;
    int j;

    i = 0;
    while(matrix[i])
    {
        j = 0;
        while(matrix[i][j])
        {
            if(matrix[i][j] == 'E' || matrix[i][j] == 'C')
            {
                free_matrix(matrix);
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int flood_fill_execution(t_map *map)
{
    int i;
    char **matrix_copy;

    i = 0;
    matrix_copy = ft_calloc(map->rows + 1, sizeof(char *));
    if(!matrix_copy)
        return (exit_game(map, "Error: Flood fill allocation failed.\n"), -1);
    while(i < map->rows)
    {
        matrix_copy[i] = ft_strdup(map->matrix[i]);
        if(!matrix_copy[i])
        {
            free_matrix(matrix_copy);
            return (exit_game(map, "Error: Flood fill allocation failed.\n"), -1);
        }
        i++;
    }
    matrix_copy[i] = NULL;
    flood_fill(matrix_copy, map->x, map->y, map);
    if(validate_flood_fill(matrix_copy) < 0)
        return (exit_game(map, "Error: Map is not valid (unreachable E or C).\n"), -1);
    free_matrix(matrix_copy);
    return (0);
}