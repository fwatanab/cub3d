/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/12 17:31:34 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		*conf;
	t_camera	*player;
	t_ray		*ray;
	t_texture	tex;

	if (argc != 2)
		error("Error: Invalid number of arguments.");
	conf = parser(argv);
	player = init_player(conf);
	ray = init_ray();
	calculate_ray_direction(ray, player);
	perform_dda(player, ray, conf);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	tex = load_texture(vars, conf);
	double	wall_dist = 20; //テスト用
	draw_wall(vars, wall_dist);
	mlx_loop(vars.mlx);
	map_free(conf);
	free(player);
	free(ray);
	return (0);
}

