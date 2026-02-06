/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by epandele          #+#    #+#             */
/*   Updated: 2026/02/06 11:29:57 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
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

int	init_matrix(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		row;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map->matrix = ft_calloc(map->rows + 1, sizeof(char *));
	if (!map->matrix)
		return (close(fd), 0);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->matrix[row] = ft_strdup(line);
		free(line);
		if (!map->matrix[row])
			return (free_matrix(map), close(fd), 0);
		row++;
		line = get_next_line(fd);
	}
	map->matrix[row] = NULL;
	close(fd);
	return (1);
}