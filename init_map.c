#include "so_long.h"

int init_map(t_map *map, char *file)
{
    int     fd;
    char    *line;
    int     len;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);

    map->rows = 0;
    map->column = 0;

    line = get_next_line(fd);
    while (line)
    {
        len = ft_strlen(line);
        if (line[len - 1] == '\n')
            len--;

        if (len > map->column)
            map->column = len;

        map->rows++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}


int init_matrix(t_map *map, char *file)
{
    int     fd;
    char    *line;
    int     row;
    int     len;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);

    map->matrix = ft_calloc(map->rows, sizeof(char *));
    if (!map->matrix)
        return (0);

    row = 0;
    line = get_next_line(fd);
    while (line)
    {
        len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';

        map->matrix[row] = ft_calloc(map->column + 1, sizeof(char));
        if (!map->matrix[row])
            return (0);

        ft_strncpy(map->matrix[row], line, map->column);
        map->matrix[row][map->column] = '\0';

        free(line);
        line = get_next_line(fd);
        row++;
    }
    close(fd);
    return (1);
}
