/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/07 16:02:30 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parser_print(t_map *conf)
{
	size_t	i;

	printf("---------------------------------------------\n");
	printf("NO = %s\n", conf->no);
	printf("SO = %s\n", conf->so);
	printf("WE = %s\n", conf->we);
	printf("EA = %s\n\n", conf->ea);
	printf("F = %d,%d,%d\n", conf->f->r, conf->f->g, conf->f->b);
	printf("C = %d,%d,%d\n\n", conf->c->r, conf->c->g, conf->c->b);
	printf("map:\n");
	i = 0;
	while (conf->map[i])
		printf("-> %s\n", conf->map[i++]);
}
