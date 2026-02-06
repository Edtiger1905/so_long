/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:24:09 by epandele          #+#    #+#             */
/*   Updated: 2026/02/06 17:26:52 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game, t_map *map)
{
	game->win_width = map->column * map->img_width;
	game->win_height = map->rows * map->img_height;
	game->map_width = map->column;
	game->map_height = map->rows;
}
