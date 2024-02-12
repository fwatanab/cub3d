/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:21:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/12 17:33:45 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vars	*vars_init()
{
	t_vars	*vars;

	vars = malloc(sizeof(char));
	if (!vars)
		error("Error: Malloc failure.");
	return (vars);
}

int	search_player(char **map, int flag)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				if (flag)
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_camera	*init_player(t_map *conf)
{
	t_camera	*player;

	player = malloc(sizeof(t_camera));
	if (!player)
		error("Error: Malloc failure.");
	player->pos_x = search_player(conf->map, 1);
	player->pos_y = search_player(conf->map, 0);
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 1;
	return (player);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		error("Error: Malloc failure.");
	return (ray);
}

t_texture	load_texture(t_vars vars, t_map *conf)
{
	t_texture	tex;

	tex.no = mlx_xpm_file_to_image(vars.mlx, conf->no, (int *)60, (int *)60);
	tex.so = mlx_xpm_file_to_image(vars.mlx, conf->so, (int *)60, (int *)60);
	tex.we = mlx_xpm_file_to_image(vars.mlx, conf->we, (int *)60, (int *)60);
	tex.ea = mlx_xpm_file_to_image(vars.mlx, conf->ea, (int *)60, (int *)60);
	return (tex);
}
