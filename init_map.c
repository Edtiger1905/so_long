#include "so_long.h"

int init_map(t_map *map, char *file)
{
    int     fd_in;
    char    *line;

    fd_in = open(file, O_RDONLY);
    if (fd_in == -1)
        return (0);

    map->rows = 0;
    map->column = 0;

    line = get_next_line(fd_in);
    while (line != NULL)
    {
        if (map->column < ft_strlen(line))
            map->column = ft_strlen(line);
        map->rows++;
        free(line);
        line = get_next_line(fd_in);
    }
    close(fd_in);
    return (1);
}

int init_matrix(t_map *map, char *file)
{
    int     fd_in;
    char    *line;
    int     row;

    fd_in = open(file, O_RDONLY);
    if (fd_in == -1)
        return (0);

    map->matrix = ft_calloc(map->rows, sizeof(char *));
    if(!map->matrix)
        return(0);
    row = 0;
    line = get_next_line(fd_in);
    while (line != NULL)
    {
        map->matrix[row] = ft_calloc(map->column + 1, sizeof(char));
        if(!map->matrix[row])
            return(0);
        ft_strncpy(map->matrix[row], line, map->column);
        map->matrix[row][map->column] = '\0';
        free(line);
        row++;
        line = get_next_line(fd_in);
    }
    close(fd_in);
    return (1);
}
