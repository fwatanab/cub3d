/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:56:25 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/11 19:23:57 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

size_t	count_semicolon(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

void	change_rgb(t_rgb *rgb, char *str)
{
	char	**result;
	size_t	i;

	result = ft_split(str, ',');
	i = 0;
	if (result)
		rgb->r = ft_atoi(result[i++]);
	if (result)
		rgb->g = ft_atoi(result[i++]);
	if (result)
		rgb->b = ft_atoi(result[i]);
	array_free(result);
}

bool	str_all_one(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (false);
	while (*str)
	{
		if (!(*str == '1' || *str == ' '))
		{
			return (false);
		}
		else if (*str == '1')
			count++;
		str++;
	}
	if (!count)
		return (false);
	return (true);
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
