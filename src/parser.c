/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:35:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/05/08 15:17:23 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*space_trim(char *str)
{
	if (!str)
		return (str);
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	return (str);
}

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
		str = space_trim(file[i]);
		if (ft_strncmp(str, key, key_len) == 0)
		{
			str = str + key_len;
			str = space_trim(str);
			result = ft_strdup(str);
			return (result);
		}
		i++;
	}
	return (NULL);
}

static t_rgb	*parse_rgb(char **file, char *key)
{
	t_rgb	*rgb;
	char	*str;

	str = get_key_value(file, key);
	if (!str)
		return (NULL);
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error("Error: Malloc failure.");
	if (count_semicolon(str) != 2 || change_rgb(rgb, str) == 1)
	{
		free(str);
		free(rgb);
		return (NULL);
	}
	free(str);
	return (rgb);
}

char	**parse_map(char **file)
{
	char	**map;
	char	*s;
	int		count;

	count = 0;
	while (*file)
	{
		if (count >= 6)
		{
			map = input_map(file);
			return (map);
		}
		s = space_trim(*file);
		if (*s)
		{
			if (ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
				|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0
				|| ft_strncmp(s, "F", 1) == 0 || ft_strncmp(s, "C", 1) == 0)
				count++;
			else
				return (NULL);
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
	conf->col = -1;
	conf->row = -1;
	conf->map = parse_map(file);
	conf->map_copy = parse_map(file);
	conf->error_flg = 0;
	array_free(file);
	return (conf);
}
