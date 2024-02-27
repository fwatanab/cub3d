/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:09 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/27 18:02:30 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
	t_vars vars;
	t_map *conf;
	t_data *data;

	if (argc != 2)
		error("Error: Invalid number of arguments.");
	conf = parser(argv);
	parser_print(conf);
	map_free(conf);
	vars.mlx = mlx_init();
	data = malloc(sizeof(t_data));
	data->vars = vars;
	data->map = *conf;
	key_hook(data);
	//	vars.mlx_win = mlx_new_window(vars.mlx, 1400, 700, "cub3d");
	//	mlx_loop(vars.mlx);
	system("leaks -q cub3d");
	return (0);
}
