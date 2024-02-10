/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/10 23:14:06 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		*conf;
	t_camera	*player;

	if (argc != 2)
		error("Error: Invalid number of arguments.");
	conf = parser(argv);
	player = init_player(conf);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1400, 700, "cub3d");
	mlx_loop(vars.mlx);
	map_free(conf);
	return (0);
}

