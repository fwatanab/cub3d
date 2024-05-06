/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:02:13 by fwatanab          #+#    #+#             */
/*   Updated: 2024/05/06 20:59:00 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	array_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	map_error(char *str, t_map *conf)
{
	ft_printf("%s\n", str);
	map_free(conf);
	exit(EXIT_FAILURE);
}

void	check_parse(t_map *conf)
{
	if (!conf->no || !conf->so || !conf->we || !conf->ea)
		map_error("map_error", conf);
	else if (!conf->f || !conf->c)
		map_error("map_error", conf);
	else if ((conf->f->r > 0 && conf->f->r > 255) || (conf->f->g > 0
			&& conf->f->g > 255) || (conf->f->b > 0 && conf->f->b > 255))
		map_error("map_error", conf);
	else if ((conf->c->r > 0 && conf->c->r > 255) || (conf->c->g > 0
			&& conf->c->g > 255) || (conf->c->b > 0 && conf->c->b > 255))
		map_error("map_error", conf);
	else if (!conf->map)
		map_error("map_error", conf);
}
