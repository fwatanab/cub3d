/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:39:32 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/11 17:40:00 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

t_tex_img	init_img(t_vars *vars)
{
	t_tex_img	img;

	img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.pixel, &img.len, &img.end);
	return (img);
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
