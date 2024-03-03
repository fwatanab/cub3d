/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:21:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/03 22:51:23 by fwatanab         ###   ########.fr       */
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
	switch (direction)
	{
		case 'N':
			player->dir_x = 0;
			player->dir_y = -1;
			player->plane_x = 0.66;
			player->plane_y = 0;
			player->dir_angle = 0;
			break;
		case 'S':
			player->dir_x = 0;
			player->dir_y = 1;
			player->plane_x = -0.66;
			player->plane_y = 0;
			player->dir_angle = 180;
			break;
		case 'W':
			player->dir_x = -1;
			player->dir_y = 0;
			player->plane_x = 0;
			player->plane_y = -0.66;
			player->dir_angle = 270;
			break;
		case 'E':
			player->dir_x = 1;
			player->dir_y = 0;
			player->plane_x = 0;
			player->plane_y = 0.66;
			player->dir_angle = 90;
			break;
	}
	return (player);
}

static t_tex_img	load_img(t_vars vars, char *file)
{
	t_tex_img	tex;
	int			x;
	int			y;

	tex.img = mlx_xpm_file_to_image(vars.mlx, file, &x, &y);
	if (!tex.img)
		error("Error: Failed to load wall texture.");
	tex.addr = mlx_get_data_addr(tex.img, &tex.pixel, &tex.len, &tex.end);
	return (tex);
}

t_textur	load_textur(t_vars vars, t_map *conf)
{
	t_textur	tex;

	tex.no = load_img(vars, conf->no);
	tex.so = load_img(vars, conf->so);
	tex.we = load_img(vars, conf->we);
	tex.ea = load_img(vars, conf->ea);
	return (tex);
}
