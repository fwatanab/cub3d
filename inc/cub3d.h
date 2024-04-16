/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:14:57 by fwatanab          #+#    #+#             */
/*   Updated: 2024/04/16 14:30:11 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 60
# define TEX_HEIGHT 60

# define MOVESPEED 0.1
# define ROTSPEED 0.1

//hook
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct t_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	*f;
	t_rgb	*c;
	char	**map;
}	t_map;

typedef struct s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
}	t_camera;

typedef struct s_tex_img
{
	void	*img;
	char	*addr;
	int		pixel;
	int		len;
	int		end;
}	t_tex_img;

typedef struct s_textur
{
	t_tex_img	no;
	t_tex_img	so;
	t_tex_img	we;
	t_tex_img	ea;
}	t_textur;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_map		*conf;
	t_camera	*player;
	t_textur	tex;
	char		*buf;
}	t_vars;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	ray_angle;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_draw
{
	int		wall_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		color;
}	t_draw;

char		**input_file(char *file);
t_map		*parser(char **argv);
void		change_rgb(t_rgb *rgb, char *str);
size_t		count_semicolon(char *str);
bool		str_all_one(char *str);
size_t		array_len(char **str);
char		**input_map(char **str);
t_textur	load_textur(t_vars vars, t_map *conf);
void		calculate_ray_direction(t_ray *ray, t_camera *player, int x);
void		perform_dda(t_camera *player, t_ray *ray, t_map *conf);
double		get_wall_dist(t_ray *ray, t_camera *player);
void		draw_wall(t_vars *vars, t_ray *ray, int x, char *buf);
void		draw_floor_and_ceiling(t_vars *vars, t_tex_img *buf);

//key_hook
void		hook(t_vars *vars);
void		move_forward_backward(t_camera *player, \
		t_map *conf, char direction);
void		strafe_left_right(t_camera *player, t_map *conf, char direction);
void		rotate_player(t_camera *player, char direction);

//init
t_vars		*vars_init(void);
t_camera	*init_player(t_map *conf);
void		set_direction(t_camera *player, char direction);
t_ray		*init_ray(void);
t_tex_img	init_img(t_vars *vars);

//map_error_check
bool		map_error_check(t_map *conf);

//error_free
void		error(char *str);
void		array_free(char **str);
void		map_free(t_map *conf);

//ft_utils
char		*ft_strndup(const char *s1, size_t n);
int			ft_strcmp(const char *s1, const char *s2);

//print for debug
void		parser_print(t_map *conf);

//map_error_utils
void		flg_check(int *l, int *l_flg, int cnt);
#endif
