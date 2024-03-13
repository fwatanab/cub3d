/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/11 19:36:46 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render_frame(void *param)
{
	t_vars		*vars;
	t_ray		ray;
	int			x;
	t_tex_img	img;

	vars = (t_vars *)param;
	img = init_img(vars);
	x = 0;
	draw_floor_and_ceiling(vars, &img);
	while (x < WIN_WIDTH)
	{
		calculate_ray_direction(&ray, vars->player, x);
		perform_dda(vars->player, &ray, vars->conf);
		draw_wall(vars, &ray, x, img.addr);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		error("Error: Invalid number of arguments.");
	vars.conf = parser(argv);
	vars.player = init_player(vars.conf);
	vars.mlx = mlx_init();
	vars.tex = load_textur(vars, vars.conf);
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	hook(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
