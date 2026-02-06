#include "../includes/so_long.h"

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
    while (line != NULL)
    {
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        // Copia TUTTA la riga, non solo map->column caratteri
        map->matrix[row] = ft_strdup(line);
        if(!map->matrix[row])
            return (0);
        free(line);
        row++;
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}
