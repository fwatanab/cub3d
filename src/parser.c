/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:35:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/07 16:02:04 by fwatanab         ###   ########.fr       */
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
	free(str);
	return (rgb);
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
