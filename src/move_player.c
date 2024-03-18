/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:11:38 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/18 16:31:39 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward_backward(t_camera *player, t_map *conf, char direction)
{
	if (direction == 'w')
	{
		if (conf->map[(int)(player->pos_y + player->dir_y * MOVESPEED)][\
				(int)(player->pos_x + player->dir_x * MOVESPEED)] != '1')
		{
			player->pos_x += player->dir_x * MOVESPEED;
			player->pos_y += player->dir_y * MOVESPEED;
		}
	}
	else if (direction == 's')
	{
		if (conf->map[(int)(player->pos_y - player->dir_y * MOVESPEED)][\
				(int)(player->pos_x - player->dir_x * MOVESPEED)] != '1')
		{
			player->pos_x -= player->dir_x * MOVESPEED;
			player->pos_y -= player->dir_y * MOVESPEED;
		}
	}
}

void	strafe_left_right(t_camera *player, t_map *conf, char direction)
{
	if (direction == 'a')
	{
		if (conf->map[(int)(player->pos_y - player->dir_x * MOVESPEED)][\
				(int)(player->pos_x + player->dir_y * MOVESPEED)] != '1')
		{
			player->pos_x += player->dir_y * MOVESPEED;
			player->pos_y -= player->dir_x * MOVESPEED;
		}
	}
	else if (direction == 'd')
	{
		if (conf->map[(int)(player->pos_y + player->dir_x * MOVESPEED)][\
				(int)(player->pos_x - player->dir_y * MOVESPEED)] != '1')
		{
			player->pos_x -= player->dir_y * MOVESPEED;
			player->pos_y += player->dir_x * MOVESPEED;
		}
	}
}

void	rotate_player(t_camera *player, char direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rs;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	rs = ROTSPEED;
	if (direction != 'L' && direction != 'R')
		return ;
	if (direction == 'L')
		rs = -ROTSPEED;
	player->dir_x = player->dir_x * cos(rs) - player->dir_y * sin(rs);
	player->dir_y = old_dir_x * sin(rs) + player->dir_y * cos(rs);
	player->plane_x = player->plane_x * cos(rs) - player->plane_y * sin(rs);
	player->plane_y = old_plane_x * sin(rs) + player->plane_y * cos(rs);
}
