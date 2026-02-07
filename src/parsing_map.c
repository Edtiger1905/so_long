/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:25:17 by epandele          #+#    #+#             */
/*   Updated: 2026/02/07 12:42:09 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	load_images(t_map *map, void *mlx)
{
	if (!map->img_wall)
		map->img_wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm",
				&map->img_width, &map->img_height);
	if (!map->img_floor)
		map->img_floor = mlx_xpm_file_to_image(mlx, "./img/floor.xpm",
				&map->img_width, &map->img_height);
	if (!map->img_exit)
		map->img_exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm",
				&map->img_width, &map->img_height);
	if (!map->img_player)
		map->img_player = mlx_xpm_file_to_image(mlx, "./img/testcp.xpm",
				&map->img_width, &map->img_height);
	if (!map->img_collectibles)
		map->img_collectibles = mlx_xpm_file_to_image(mlx,
				"./img/collectibles.xpm", &map->img_width, &map->img_height);
	if (!map->img_wall || !map->img_floor || !map->img_exit
		|| !map->img_player || !map->img_collectibles)
		return (0);
	return (1);
}

static void	put_tile(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, img,
		x * map->img_width, y * map->img_height);
}

static void	draw_map_tile(t_map *map, int i, int j)
{
	if (map->matrix[i][j] == '1')
		put_tile(map, map->img_wall, j, i);
	else if (map->matrix[i][j] == '0')
		put_tile(map, map->img_floor, j, i);
	else if (map->matrix[i][j] == 'E')
		put_tile(map, map->img_exit, j, i);
	else if (map->matrix[i][j] == 'C')
		put_tile(map, map->img_collectibles, j, i);
	else if (map->matrix[i][j] == 'P')
		put_tile(map, map->img_player, j, i);
}

int	read_matrix(t_map *map, void *mlx, void *win)
{
	int	i;
	int	j;

	if (!mlx || !win || !map || !map->matrix)
		return (0);
	map->mlx = mlx;
	map->win = win;
	if (!load_images(map, mlx))
		return (0);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->column)
		{
			draw_map_tile(map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
