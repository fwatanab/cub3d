/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:06:24 by fwatanab          #+#    #+#             */
/*   Updated: 2024/03/11 19:35:08 by fwatanab         ###   ########.fr       */
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

static char	**read_lines_into_array(int fd, char **str)
{
	char	*line;
	int		i;

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
	return (str);
}

char	**input_file(char *file)
{
	int		fd;
	char	**str;

	str = malloc(sizeof(char *) * (map_size(file) + 1));
	if (!str)
		error("Error: Malloc failure.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		error("Error: Failed to open the file.");
	}
	str = read_lines_into_array(fd, str);
	close(fd);
	return (str);
}
