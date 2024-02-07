/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:35:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/07 09:53:42 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*get_key_value(char **file, char *key)
{
	char	*result;
	char	*str;
	size_t	i;
	size_t	key_len;

	str = NULL;
	i = 0;
	key_len = ft_strlen(key);
	while (file[i])
	{
		if (ft_strncmp(file[i], key, key_len) == 0)
		{
			str = file[i] + key_len;
			while (*str == ' ' || *str == '\t' || *str == '\n'
					|| *str == '\v' || *str == '\f' || *str == '\r')
				str++;
			result = ft_strdup(str);
			return (result);
		}
		i++;
	}
	return (NULL);
}

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

static void	change_rgb(t_rgb *rgb, char *str)
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

static t_rgb	*parse_rgb(char **file, char *key)
{
	t_rgb	*rgb;
	char	*str;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error("Error: Malloc failure.");
	str = get_key_value(file, key);
	if (count_semicolon(str) != 2)
	{
		free(str);
		return (NULL);
	}
	change_rgb(rgb, str);
	return (rgb);
}

bool	str_all_one(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != ' ')
			return (false);
		str++;
	}
	return (true);
}

size_t	array_len(char **str)
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
	size_t	map_size;
	size_t	i;

	map_size = array_len(str);
	map = malloc(sizeof(char *) * map_size + 1);
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
	return (map);

}

char	**parse_map(char **file)
{
	char	**map;

	while (*file)
	{
		if (str_all_one(*file))
		{
			map = input_map(file);
			return (map);
		}
		file++;
	}
	return (NULL);
}

t_map	*parser(char **argv)
{
	t_map	*conf;
	char	**file;

	file = input_file(argv[1]);
	conf = malloc(sizeof(t_map));
	if (!conf)
	{
		array_free(file);
		error("Error: Malloc failure.");
	}
	conf->no = get_key_value(file, "NO");
	conf->so = get_key_value(file, "SO");
	conf->we = get_key_value(file, "WE");
	conf->ea = get_key_value(file, "EA");
	conf->f = parse_rgb(file, "F");
	conf->c = parse_rgb(file, "C");
	conf->map = parse_map(file);
	array_free(file);
	return (conf);
}
