#include "cub3d.h"

int player_move(int key, t_data data)
{
	if (key == 1)
		return (0);
	(void)data;
	return (0);
}

void key_hook(t_data *data)
{
	mlx_hook(data->vars.mlx_win, KeyPress, KeyPressMask, player_move, data);
	mlx_loop(data->vars.mlx_win);
}