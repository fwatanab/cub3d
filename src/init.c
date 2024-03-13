/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:21:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/11 17:59:09 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vars	*vars_init(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(char));
	if (!vars)
		error("Error: Malloc failure.");
	return (vars);
}

int	search_player(char **map, char *direction)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				*direction = map[y][x];
				return (y * 100 + x);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

t_camera	*init_player(t_map *conf)
{
	t_camera	*player;
	int			position;
	char		direction;

	player = malloc(sizeof(t_camera));
	if (!player)
		error("Error: Malloc failure.");
	position = search_player(conf->map, &direction);
	if (position == -1)
		error("Player not found.");
	player->pos_x = position % 100;
	player->pos_y = position / 100;
	set_direction(player, direction);
	return (player);
}
