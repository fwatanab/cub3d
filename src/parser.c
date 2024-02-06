/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:35:47 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/07 01:30:52 by fwatanab         ###   ########.fr       */
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
	array_free(file);
	return (conf);
}
