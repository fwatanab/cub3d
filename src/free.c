/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:32:03 by fwatanab          #+#    #+#             */
/*   Updated: 2024/05/05 15:18:55 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_free(t_map *conf)
{
	if (conf->no)
		free(conf->no);
	if (conf->so)
		free(conf->so);
	if (conf->we)
		free(conf->we);
	if (conf->ea)
		free(conf->ea);
	if (conf->f)
		free(conf->f);
	if (conf->c)
		free(conf->c);
	if (conf->map)
		array_free(conf->map);
	if (conf->map_copy)
		array_free(conf->map_copy);
	free(conf);
}
