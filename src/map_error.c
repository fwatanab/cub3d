/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:09:20 by stakimot          #+#    #+#             */
/*   Updated: 2024/04/16 17:29:28 by stakimot         ###   ########.fr       */
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

bool	char_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			if (map_char_cmp(map[i][j++]) == false)
				return (false);
		}
		printf("\n");
		i++;
	}
	return (true);
}

// bool	top_bottom_check(char *str, int *left, int *right, int flg)
// {
// 	int	cnt;
// 	int	left_flg;

// 	cnt = 0;
// 	left_flg = 0;
// 	while (str[cnt])
// 	{
// 		if (str[cnt] == '1')
// 		{
// 			if (left_flg == 0)
// 			{
// 				*left = cnt;
// 				left_flg = 1;
// 			}
// 			*right = cnt;
// 		}
// 		if (cnt < *left && str[cnt] != '1' && flg == 1)
// 			return (false);
// 		if (cnt > *right && str[cnt] != '1' && flg == 1)
// 		{
// 			printf("test!!!\n");
// 			return (false);
// 		}
// 		if (str[cnt] != '1' && str[cnt] != ' ')
// 			return (false);
// 		cnt++;
// 	}
// 	return (true);
// }

bool	top_bottom_check(char **map, int *left, int *right, int col)
{
	int	cnt;
	int	left_flg;

	cnt = 0;
	left_flg = 0;
	while (map[col][cnt])
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
		if (col != 0)
		{
			if ((cnt < *left && map[col][cnt] != 1 && map[col - 1][cnt] != 1) ||
				(cnt < *right && map[col][cnt] != 1 && map[col - 1][cnt] != 1))
				return (false);
		}
		if (map[col][cnt] != '1' && map[col][cnt] != ' ')
			return (false);
		cnt++;
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
		if ((cnt < *left && str[cnt] != '1')
			|| (cnt > *right && str[cnt] != '1'))
			return (false);
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

	cnt = 0;
	if (char_check(conf->map) == false)
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
	return (true);
}
