/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:21:55 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/04 20:37:49 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vars	*vars_init()
{
	t_vars	*vars;

	vars = malloc(sizeof(char));
	if (!vars)
		error("Error: Malloc failure.");
	return (vars);
}
