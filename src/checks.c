/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edtiger1905 <edtiger1905@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by epandele          #+#    #+#             */
/*   Updated: 2026/02/06 11:43:18 by edtiger1905      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(t_map *map)
{
	int	i;
	int	first_len;

	if (!map || !map->matrix)
		return (0);
	first_len = ft_strlen(map->matrix[0]);
	i = 0;
	while (i < map->rows)
	{
		if (ft_strlen(map->matrix[i]) != first_len)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_rows(t_map *map)
{
	int	i;
	
	i = 0;
	while (i < map->column)
	{
		if (map->matrix[0][i] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls\n");
			return (0);
		}
		if (map->matrix[map->rows - 1][i] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_cols(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->rows)
	{
		if (map->matrix[j][0] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls\n");	
			return (0);
		}
		if (map->matrix[j][map->column - 1] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	if (!check_walls_rows(map))
		return (0);
	if (!check_walls_cols(map))
		return (0);
	return (1);
}

int	map_extension_is_valid(char *filename, char *extension)
{
	int	filename_len;
	int	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (extension_len > filename_len)
	{
		ft_printf("Error\nInvalid filename\n");
		return (0);
	}
	if (ft_strncmp(&filename[filename_len - extension_len],
			extension, extension_len) != 0)
	{
		ft_printf("Error\nMap must have .ber extension\n");
		return (0);
	}
	return (1);
}