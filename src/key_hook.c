#include "../inc/cub3d.h"

int player_move(int key, void vars)
{
	
}

	void key_hook(t_vars vars, t_map conf)
{
	t_vars vars;

	mlx_key_hook(vars.win, KeyPress, KeyPressMask, player_move, &vars);
	mlx_loop(vars.mlx);
}