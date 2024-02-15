/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:21:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/15 21:27:01 by fwatanab         ###   ########.fr       */
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

//int	search_player(char **map, int flag)
//{
//	int	x;
//	int	y;
//
//	y = 0;
//	while (map[y])
//	{
//		x = 0;
//		while (map[y][x])
//		{
//			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
//			{
//				if (flag)
//					return (x);
//				return (y);
//			}
//			x++;
//		}
//		y++;
//	}
//	return (0);
//}

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
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				*direction = map[y][x];
				return (y * 10 + x);
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
	player->pos_x = position % 10;
	player->pos_y = position / 10;
	switch (direction)
	{
		case 'N':
			player->dir_x = 0;
			player->dir_y = -1;
			player->plane_x = 0.66;
			player->plane_y = 0;
			break;
		case 'S':
			player->dir_x = 0;
			player->dir_y = 1;
			player->plane_x = -0.66;
			player->plane_y = 0;
			break;
		case 'W':
			player->dir_x = -1;
			player->dir_y = 0;
			player->plane_x = 0;
			player->plane_y = -0.66;
			break;
		case 'E':
			player->dir_x = 1;
			player->dir_y = 0;
			player->plane_x = 0;
			player->plane_y = 0.66;
			break;
	}
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

	tex.no.img_ptr = mlx_xpm_file_to_image(vars.mlx, conf->no, (int *)60, (int *)60);
	tex.so.img_ptr = mlx_xpm_file_to_image(vars.mlx, conf->so, (int *)60, (int *)60);
	tex.we.img_ptr = mlx_xpm_file_to_image(vars.mlx, conf->we, (int *)60, (int *)60);
	tex.ea.img_ptr = mlx_xpm_file_to_image(vars.mlx, conf->ea, (int *)60, (int *)60);
	return (tex);
}
