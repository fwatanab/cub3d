/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/12 17:07:07 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_texture(t_vars vars, int start, int end, int color)
{
	while (start <= end)
	{
		mlx_pixel_put(vars.mlx, vars.mlx_win, WIN_HEIGHT / 2, start, color);
		start++;
	}
}

void	draw_wall(t_vars vars, double wall_dist)
{
	double	wall_height;
	int		start;
	int		end;

	wall_height = WIN_HEIGHT / wall_dist;
	start = -wall_dist / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = wall_dist = WIN_HEIGHT / 2 + wall_dist / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT -1;
	draw_texture(vars, start, end, 0x00FFFFFF);
}
