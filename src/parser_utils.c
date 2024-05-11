/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:56:25 by fwatanab          #+#    #+#             */
/*   Updated: 2024/05/08 15:02:22 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	count_semicolon(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

static int	check_value(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	change_rgb(t_rgb *rgb, char *str)
{
	char	**result;
	size_t	i;

	result = ft_split(str, ',');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
		i++;
	if (i != 3 || check_value(result) == 1)
	{
		array_free(result);
		return (1);
	}
	rgb->r = ft_atoi(result[0]);
	rgb->g = ft_atoi(result[1]);
	rgb->b = ft_atoi(result[2]);
	array_free(result);
	return (0);
}

size_t	array_size(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	**input_map(char **str)
{
	char	**map;
	size_t	i;

	if (!str || !*str)
		return (NULL);
	map = malloc(sizeof(char *) * (array_size(str) + 1));
	if (!map)
		error("Error: Malloc failure.");
	i = 0;
	while (*str)
	{
		map[i] = ft_strdup(*str);
		if (!map[i])
		{
			array_free(map);
			return (NULL);
		}
		i++;
		str++;
	}
	map[i] = NULL;
	return (map);
}
