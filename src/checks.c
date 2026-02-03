#include "./includes/so_long.h"

int is_rectangular(t_map *game)
{
    if(game->rows == game->column)
    {
        ft_printf("The map is not rectangular");
        return (0);
    }
    else
        return (1);
}
int map_extension_is_valid(char *filename, char *extension)
{
    int filename_len;
    int extension_len;

    filename_len = ft_strlen(filename);
    extension_len = ft_strlen(extension);

    if(extension_len > filename_len)
        return (-1);
    return(ft_strncmp(&filename[filename_len - extension_len], 
        extension, extension_len) == 0);
}
void checks(t_map *map, t_map *game,char *filename)
{
    is_rectangular(game);
    map_extension_is_valid(filename, ".ber");
}