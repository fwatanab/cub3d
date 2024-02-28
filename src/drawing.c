/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/28 18:40:29 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//static void	draw_texture(t_vars vars, int start, int end, int color)
//{
//	while (start <= end)
//	{
//		mlx_pixel_put(vars.mlx, vars.mlx_win, WIN_HEIGHT / 2, start, color);
//		start++;
//	}
//}
//
//void	get_wall_height(t_vars vars, double wall_dist)
//{
//	double	wall_height;
//	int		start;
//	int		end;
//
//	wall_height = WIN_HEIGHT / wall_dist;
//	start = -wall_dist / 2 + WIN_HEIGHT / 2;
//	if (start < 0)
//		start = 0;
//	end = wall_height = WIN_HEIGHT / 2 + wall_dist / 2;
//	if (end >= WIN_HEIGHT)
//		end = WIN_HEIGHT -1;
//	draw_texture(vars, start, end, 0x00FFFFFF);
//}

double	get_wall_dist(t_ray *ray, t_camera *player)
{
	double	wall_dist;

	if (ray->side == 0)
		wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
	printf("wall_dist %f\n", wall_dist);
	return (wall_dist);
}

void	draw_wall(t_vars vars, t_ray *ray, int x, double wall_dist)
{
	int		wall_height;
	int		draw_start;
	int		draw_end;

	if (wall_dist <= 0.0)
		wall_dist = 0.1;
	wall_height = (int)(WIN_HEIGHT / wall_dist);
	draw_start = -wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		int d = (y - draw_start) * 256;
		int	tex_y = ((d * TEX_HEIGHT) / WIN_HEIGHT) / 256;
		double	wall_x;
		if (ray->side == 0)
			wall_x = vars.player->pos_y + wall_dist * ray->dir_y;
		else
			wall_x = vars.player->pos_x + wall_dist * ray->dir_x;
		wall_x -= floor(wall_x);
		int	tex_x = (int)(wall_x * (double)TEX_WIDTH);
		if (ray->side == 0 && ray->dir_x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if (ray->side == 1 && ray->dir_y < 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		int	color = ((int *)vars.tex.no.addr)[tex_y * TEX_WIDTH + tex_x];
		mlx_pixel_put(vars.mlx, vars.mlx_win, x, y, color);
		y++;
	}
}
