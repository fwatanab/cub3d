/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:03:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/13 18:09:08 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void movement_player(t_vars *vars, char direction)
{
	if (direction == 'w')
	{
		if(vars->conf->map[(int)(vars->player->pos_y + vars->player->dir_y * MOVESPEED)][(int)(vars->player->pos_x + vars->player->dir_x * MOVESPEED)] != '1')
		{
			vars->player->pos_x += vars->player->dir_x * MOVESPEED;
			vars->player->pos_y += vars->player->dir_y * MOVESPEED;
		}
	}
	else if (direction == 's')
	{
		if(vars->conf->map[(int)(vars->player->pos_y - vars->player->dir_y * MOVESPEED)][(int)(vars->player->pos_x - vars->player->dir_x * MOVESPEED)] != '1')
		{
			vars->player->pos_x -= vars->player->dir_x * MOVESPEED;
			vars->player->pos_y -= vars->player->dir_y * MOVESPEED;
		}
	}
	else if (direction == 'a')
	{
		if(vars->conf->map[(int)(vars->player->pos_y - vars->player->dir_x * MOVESPEED)][(int)(vars->player->pos_x + vars->player->dir_y * MOVESPEED)] != '1')
		{
			vars->player->pos_x += vars->player->dir_y * MOVESPEED;
			vars->player->pos_y -= vars->player->dir_x * MOVESPEED;
		}
	}
	else if (direction == 'd')
	{
		if(vars->conf->map[(int)(vars->player->pos_y + vars->player->dir_x * MOVESPEED)][(int)(vars->player->pos_x - vars->player->dir_y * MOVESPEED)] != '1')
		{
			vars->player->pos_x -= vars->player->dir_y * MOVESPEED;
			vars->player->pos_y += vars->player->dir_x * MOVESPEED;
		}
	}
}

void rotate_player(t_vars *vars, char direction)
{
	double oldDirX = vars->player->dir_x;
	double oldPlaneX = vars->player->plane_x;

	if (direction == 'L')
	{
		vars->player->dir_x = vars->player->dir_x * cos(-ROTSPEED) - vars->player->dir_y * sin(-ROTSPEED);
		vars->player->dir_y = oldDirX * sin(-ROTSPEED) + vars->player->dir_y * cos(-ROTSPEED);
		vars->player->plane_x = vars->player->plane_x * cos(-ROTSPEED) - vars->player->plane_y * sin(-ROTSPEED);
		vars->player->plane_y = oldPlaneX * sin(-ROTSPEED) + vars->player->plane_y * cos(-ROTSPEED);
	}
	else if (direction == 'R')
	{
		vars->player->dir_x = vars->player->dir_x * cos(ROTSPEED) - vars->player->dir_y * sin(ROTSPEED);
		vars->player->dir_y = oldDirX * sin(ROTSPEED) + vars->player->dir_y * cos(ROTSPEED);
		vars->player->plane_x = vars->player->plane_x * cos(ROTSPEED) - vars->player->plane_y * sin(ROTSPEED);
		vars->player->plane_y = oldPlaneX * sin(ROTSPEED) + vars->player->plane_y * cos(ROTSPEED);
	}
}

int	close_window(t_vars *vars)
{
	array_free(vars->conf->map);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_window(vars);
	else if (keycode == 'w')
		movement_player(vars, 'w');
	else if (keycode == 'a')
		movement_player(vars, 'a');
	else if (keycode == 's')
		movement_player(vars, 's');
	else if (keycode == 'd')
		movement_player(vars, 'd');
	else if (keycode == LEFT)
		rotate_player(vars, 'L');
	else if (keycode == RIGHT)
		rotate_player(vars, 'R');
	return (0);
}

void	hook(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 17, 1L << 0, close_window, vars);
}
