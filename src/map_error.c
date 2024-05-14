/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:09:20 by stakimot          #+#    #+#             */
/*   Updated: 2024/05/11 17:00:13 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	map_char_cmp(char c)
{
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	if (c == ' ')
		return (true);
	return (false);
}

bool	char_check(t_map *conf)
{
	int	i;
	int	j;

	i = 0;
	if (!conf->map)
		return (false);
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (map_char_cmp(conf->map[i][j]) == false)
				return (false);
			if ((conf->col < 0 || conf->row < 0)
				&& (conf->map[i][j] == 'N' || conf->map[i][j] == 'S'
				|| conf->map[i][j] == 'W' || conf->map[i][j] == 'E'))
			{
				conf->col = i;
				conf->row = j;
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	top_bottom_check(char **map, int *left, int *right, int col)
{
	int	cnt;
	int	left_flg;

	cnt = -1;
	left_flg = 0;
	while (map[col][++cnt])
	{
		if (map[col][cnt] == '1')
		{
			if (left_flg == 0)
			{
				*left = cnt;
				left_flg = 1;
			}
			*right = cnt;
		}
		if ((col != 0 && cnt < *left && map[col][cnt] != 1
			&& map[col - 1][cnt] != 1) ||
			(col != 0 && cnt < *right && map[col][cnt] != 1
			&& map[col - 1][cnt] != 1))
			return (false);
		if (map[col][cnt] != '1' && map[col][cnt] != ' ')
			return (false);
	}
	return (true);
}

bool	wall_check(char *str, int *left, int *right)
{
	int	l;
	int	l_flg;
	int	r;
	int	cnt;

	cnt = 0;
	l_flg = 0;
	while (str[cnt])
	{
		if (l_flg == 0 && str[cnt] != '1' && str[cnt] != ' ')
			return (false);
		if (str[cnt] == '1')
		{
			if (l_flg == 0)
				flg_check(&l, &l_flg, cnt);
			r = cnt;
		}
		cnt ++;
	}
	*left = l;
	*right = r;
	return (true);
}

bool	map_error_check(t_map *conf)
{
	int	cnt;
	int	left;
	int	right;
	int	error;

	cnt = 0;
	error = 0;
	if (char_check(conf) == false)
		return (false);
	if (top_bottom_check(conf->map, &left, &right, cnt++) == false)
		return (false);
	while (conf->map[cnt + 1])
	{
		if (wall_check(conf->map[cnt], &left, &right) == false)
			return (false);
		cnt ++;
	}
	if (top_bottom_check(conf->map, &left, &right, cnt) == false)
		return (false);
	playable_check(conf, conf->col, conf->row);
	if (conf->error_flg != 0 || cnt * right > 8000)
		return (false);
	return (true);
}
