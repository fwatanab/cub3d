/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:48:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/18 18:44:28 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	get_wall_dist(t_ray *ray, t_camera *player)
{
	double	wall_dist;

	if (ray->side == 0)
		wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) \
					/ ray->dir_x;
	else
		wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) \
					/ ray->dir_y;
	return (wall_dist);
}

void	calculate_wall_parameters(t_vars *vars, t_ray *ray, t_draw *params, \
		double wall_dist)
{
	if (wall_dist <= 0.0)
		wall_dist = 0.1;
	params->wall_height = (int)(WIN_HEIGHT / wall_dist);
	params->draw_start = -params->wall_height / 2 + WIN_HEIGHT / 2;
	if (params->draw_start < 0)
		params->draw_start = 0;
	params->draw_end = params->wall_height / 2 + WIN_HEIGHT / 2;
	if (params->draw_end >= WIN_HEIGHT)
		params->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		params->wall_x = vars->player->pos_y + wall_dist * ray->dir_y;
	else
		params->wall_x = vars->player->pos_x + wall_dist * ray->dir_x;
	params->wall_x -= floor(params->wall_x);
}

char	*check_wall_direction(t_ray *ray, t_textur tex)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (tex.ea.addr);
		else
			return (tex.we.addr);
	}
	else
	{
		if (ray->dir_y > 0)
			return (tex.so.addr);
		else
			return (tex.no.addr);
	}
	return (NULL);
}

void	draw_wall(t_vars *vars, t_ray *ray, int x, char *buf)
{
	t_draw	params;
	double	wall_dist;
	int		d;
	int		y;
	char	*addr;

	wall_dist = get_wall_dist(ray, vars->player);
	calculate_wall_parameters(vars, ray, &params, wall_dist);
	y = params.draw_start;
	while (y < params.draw_end)
	{
		d = (y - params.draw_start) * 256;
		params.tex_y = ((d * TEX_HEIGHT) / WIN_HEIGHT) / 256;
		params.tex_x = (int)(params.wall_x * (double)TEX_WIDTH);
		if ((ray->side == 0 && ray->dir_x > 0)
			|| (ray->side == 1 && ray->dir_y > 0))
			params.tex_x = TEX_WIDTH - params.tex_x - 1;
		addr = check_wall_direction(ray, vars->tex);
		params.color = ((int *)addr)[params.tex_y * TEX_WIDTH + params.tex_x];
		*(int *)(buf + (x + y * WIN_WIDTH) * 4) = params.color;
		y++;
	}
}

void	draw_floor_and_ceiling(t_vars *vars, t_tex_img *buf)
{
	int	x;
	int	y;
	int	f_color;
	int	c_color;

	f_color = (vars->conf->f->r << 16) + (vars->conf->f->g << 8) \
			+ vars->conf->f->b;
	c_color = (vars->conf->c->r << 16) + (vars->conf->c->g << 8) \
			+ vars->conf->c->b;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				*(int *)(buf->addr + (x + y * WIN_WIDTH) \
						* (buf->pixel / 8)) = c_color;
			else
				*(int *)(buf->addr + (x + y * WIN_WIDTH) \
						* (buf->pixel / 8)) = f_color;
			x++;
		}
		y++;
	}
}
