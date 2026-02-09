/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:23:29 by epandele          #+#    #+#             */
/*   Updated: 2026/02/09 14:17:38 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_images(t_map *map)
{
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm",
			&map->img_width, &map->img_height);
	map->img_floor = mlx_xpm_file_to_image(map->mlx, "./img/ground.xpm",
			&map->img_width, &map->img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm",
			&map->img_width, &map->img_height);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm",
			&map->img_width, &map->img_height);
	map->img_collectibles = mlx_xpm_file_to_image(map->mlx,
			"./img/collectibles.xpm", &map->img_width, &map->img_height);
	if (!map->img_wall || !map->img_floor || !map->img_exit)
	{
		ft_printf("Error: Failed to load images\n");
		return (0);
	}
	if (!map->img_player || !map->img_collectibles)
	{
		ft_printf("Error: Failed to load images\n");
		return (0);
	}
	return (1);
}
