/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/15 20:06:21 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render_frame(void *param)
{
	t_vars		*vars;
	t_ray		ray;
	double		wall_dist;
	int	x;

	vars = (t_vars *)param;
//	ray = init_ray();
	x = 0;
	while (x < WIN_WIDTH)
	{
		// レイの初期設定
		calculate_ray_direction(&ray, vars->player, x);
		// レイキャスティングの実行
		perform_dda(vars->player, &ray, vars->conf);
		// 壁までの距離を計算
		wall_dist = get_wall_dist(&ray, vars->player);
		// 壁を描画
		draw_wall(*vars, x, wall_dist);
		x++;
	}
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
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

