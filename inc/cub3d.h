/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:14:57 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/10 23:06:32 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
//# include "mlx.h" // 42 iMac
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct t_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	struct s_rgb	*f;
	struct s_rgb	*c;
	char			**map;
}	t_map;

typedef struct s_camera
{
	int	dir_x;    // プレイヤーの方向ベクトルのX成分
	int	dir_y;    // プレイヤーの方向ベクトルのY成分
	int	plane_x;  // カメラ平面のXベクトル成分（視野角に影響）
	int	plane_y;  // カメラ平面のYベクトル成分（視野角に影響）
	int	pos_x;    // プレイヤーのX座標
	int	pos_y;    // プレイヤーのY座標
}	t_camera;

typedef struct s_player
{
	char	angle;
	int		p_x;
	int		p_y;
}	t_player;

char	**input_file(char *file);
t_map	*parser(char **argv);
void	change_rgb(t_rgb *rgb, char *str);
size_t	count_semicolon(char *str);
bool	str_all_one(char *str);
size_t	array_len(char **str);
char	**input_map(char **str);

//init
t_vars		*vars_init();
t_camera	*init_player(t_map *conf);

//error_free
void	error(char *str);
void	array_free(char **str);
void	map_free(t_map *conf);

//ft_utils
char	*ft_strndup(const char *s1, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

//print for debug
void	parser_print(t_map *conf);
#endif
