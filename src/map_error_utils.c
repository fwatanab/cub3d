/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:22:54 by stakimot          #+#    #+#             */
/*   Updated: 2024/05/11 11:17:16 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	flg_check(int *l, int *l_flg, int cnt)
{
	*l = cnt;
	*l_flg = 1;
	return ;
}

void	playable_check(t_map *conf, int col, int row)
{
	if (col < 0 || row < 0)
		return ;
	if (conf->map_copy[col][row] == ' ' || conf->map_copy[col][row] == '\0')
	{
		conf->error_flg = 1;
		return ;
	}
	if (conf->map_copy[col][row] == '0' || conf->map_copy[col][row] == 'N' ||
		conf->map_copy[col][row] == 'S' || conf->map_copy[col][row] == 'W' ||
		conf->map_copy[col][row] == 'E')
	{
		conf->map_copy[col][row] = 'T';
		playable_check(conf, col - 1, row);
		playable_check(conf, col + 1, row);
		playable_check(conf, col, row - 1);
		playable_check(conf, col, row + 1);
	}
	return ;
}
