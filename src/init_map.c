#include "so_long.h"

int init_map(t_game *game, char *file)
{
    int     fd_in;
    char    *line;

    fd_in = open(file, O_RDONLY);
    if (fd_in == -1)
        return (0);

    game->map_height = 0;
    game->map_width = 0;

    line = get_next_line(fd_in);
    while (line != NULL)
    {
        if ((size_t)game->map_width < ft_strlen(line))
            game->map_width = ft_strlen(line);
        game->map_height++;
        free(line);
        line = get_next_line(fd_in);
    }
    close(fd_in);
    return (1);
}

