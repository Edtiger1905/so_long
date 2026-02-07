/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by epandele          #+#    #+#             */
/*   Updated: 2026/02/07 12:34:11 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_line_length(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

int	init_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map->rows = 0;
	map->column = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		len = count_line_length(line);
		if (len > map->column)
			map->column = len;
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int	process_line(t_map *map, char *line, int row)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	map->matrix[row] = ft_strdup(line);
	if (!map->matrix[row])
		return (0);
	return (1);
}

int	init_matrix(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		row;

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
		if (!process_line(map, line, row))
			return (0);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
