/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/07 18:56:30 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	get_wall_dist(t_ray *ray, t_camera *player)
{
	double	wall_dist;

	if (ray->side == 0)
		wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
	return (wall_dist);
}

void	draw_wall(t_vars *vars, t_ray *ray, int x, double wall_dist, char *buf)
{
	int		wall_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;

	if (wall_dist <= 0.0)
		wall_dist = 0.1;
	wall_height = (int)(WIN_HEIGHT / wall_dist);
	draw_start = -wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		wall_x = vars->player->pos_y + wall_dist * ray->dir_y;
	else
		wall_x = vars->player->pos_x + wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		int d = (y - draw_start) * 256;
		int	tex_y = ((d * TEX_HEIGHT) / WIN_HEIGHT) / 256;
		int	tex_x = (int)(wall_x * (double)TEX_WIDTH);
		if ((ray->side == 0 && ray->dir_x > 0)
			|| (ray->side == 1 && ray->dir_y > 0))
			tex_x = TEX_WIDTH - tex_x - 1;
		int	color = ((int *)vars->tex.no.addr)[tex_y * TEX_WIDTH + tex_x];
		*(int *)(buf + (x + y * WIN_WIDTH) * 4) = color;
		y++;
	}
}

void	draw_floor_and_ceiling(t_vars *vars, t_tex_img *buf)
{
	int			x;
	int			y;
	int			f_color;
	int			c_color;
	int			color;

	f_color = (vars->conf->f->r << 16) + (vars->conf->f->g << 8) + vars->conf->f->b;
	c_color = (vars->conf->c->r << 16) + (vars->conf->c->g << 8) + vars->conf->c->b;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = (y < WIN_HEIGHT / 2) ? c_color : f_color;
			*(int *)(buf->addr + (x + y * WIN_WIDTH) * (buf->pixel / 8)) = color;
			x++;
		}
		y++;
	}
}
