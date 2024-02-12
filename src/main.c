/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/12 16:28:06 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		*conf;
	t_camera	*player;
	t_ray		*ray;

	if (argc != 2)
		error("Error: Invalid number of arguments.");
	conf = parser(argv);
	player = init_player(conf);
	ray = init_ray();
	int	screen = 600;
	calculate_ray_direction(ray, player, screen, screen / 2);
	perform_dda(player, ray, conf);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1400, 700, "cub3d");
	mlx_loop(vars.mlx);
	map_free(conf);
	free(player);
	free(ray);
	return (0);
}

