/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/15 18:18:35 by fwatanab         ###   ########.fr       */
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

void	get_wall_height(t_vars vars, double wall_dist)
{
	double	wall_height;
	int		start;
	int		end;

	wall_height = WIN_HEIGHT / wall_dist;
	start = -wall_dist / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = wall_height = WIN_HEIGHT / 2 + wall_dist / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT -1;
	draw_texture(vars, start, end, 0x00FFFFFF);
}

double	get_wall_dist(t_ray *ray, t_camera *player)
{
	double	wall_dist;

	if (ray->side == 0)
		wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
	return (wall_dist);
}

void	draw_wall(t_vars vars, t_ray *ray, t_camera *player)
{
	double	wall_dist;

	wall_dist = get_wall_dist(ray, player);
	get_wall_height(vars, wall_dist);
}
