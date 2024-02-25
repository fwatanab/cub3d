/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:24 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/12 03:08:56 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	ft_strnlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t	map_size(char *file)
{
	int		fd;
	size_t	len;
	char	*line;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: Failed to open the file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		len++;
	}
	close(fd);
	return (len);
}

char	**input_file(char *file)
{
	int		fd;
	char	*line;
	char	**str;
	size_t	i;

	str = malloc(sizeof(char *) * (map_size(file) + 1));
	if (!str)
		error("Error: Malloc failure.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		error("Error: Failed to open the file.");
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str[i] = ft_strndup(line, ft_strnlen(line));
		free(line);
		if (!str[i])
		{
			array_free(str);
			error("Error: Malloc failure.");
		}
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}
