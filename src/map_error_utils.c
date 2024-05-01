/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:22:54 by stakimot          #+#    #+#             */
/*   Updated: 2024/05/01 16:05:21 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	flg_check(int *l, int *l_flg, int cnt)
{
	*l = cnt;
	*l_flg = 1;
	return ;
}

void	playable_check(char **map, char **copy, int col, int row, int *error)
{
	if (col < 0 || row < 0)
		return ;
	if (copy[col][row] == ' ')
	{
		*error = 1;
		return ;
	}
	if (copy[col][row] == '0' || copy[col][row] == 'N' ||
		copy[col][row] == 'S' || copy[col][row] == 'W' ||
		copy[col][row] == 'E')
	{
		copy[col][row] = 'T';
		playable_check(map, copy, col - 1, row, error);
		playable_check(map, copy, col + 1, row, error);
		playable_check(map, copy, col, row - 1, error);
		playable_check(map, copy, col, row + 1, error);
	}
	return ;
}
