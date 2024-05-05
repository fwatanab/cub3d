/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:03:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/04/15 17:39:37 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	else if (keycode == W)
		move_forward_backward(vars->player, vars->conf, 'w');
	else if (keycode == A)
		strafe_left_right(vars->player, vars->conf, 'a');
	else if (keycode == S)
		move_forward_backward(vars->player, vars->conf, 's');
	else if (keycode == D)
		strafe_left_right(vars->player, vars->conf, 'd');
	else if (keycode == LEFT)
		rotate_player(vars->player, 'L');
	else if (keycode == RIGHT)
		rotate_player(vars->player, 'R');
	return (0);
}

void	hook(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 17, 1L << 0, close_window, vars);
}
