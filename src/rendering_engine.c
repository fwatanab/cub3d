#include "../inc/cub3d.h"

void	calculate_ray_direction(t_ray *ray, t_camera *player, int x)
{
	double	camera_x;
	double	red_to_deg;

	camera_x = 2 * x / (double)WIN_WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * camera_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_x;
	red_to_deg = 180.0 / M_PI;
	ray->ray_angle = player->dir_angle + atan2(ray->dir_y, ray->dir_x) * red_to_deg;
	if (ray->ray_angle < 0)
		ray->ray_angle += 360;
}

void	execute_dda(t_ray *ray, t_map *conf)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (conf->map[ray->map_x][ray->map_y] == '1')
			hit = 1;
	}
}

void	perform_dda(t_camera *player, t_ray *ray, t_map *conf)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = (ray->dir_x == 0) ? 1e30 : fabs(1 / ray->dir_x);
	ray->delta_dist_y = (ray->dir_y == 0) ? 1e30: fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x= 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
	execute_dda(ray, conf);
	printf("map_x: %d, map_y: %d, side_dist_x: %f, side_dist_y: %f\n", ray->map_x, ray->map_y, ray->side_dist_x, ray->side_dist_y);
}
