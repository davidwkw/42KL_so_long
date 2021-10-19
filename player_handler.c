#include "so_long.h"

void	*select_idle_img(t_vars *mlx, unsigned int state)
{
	if (mlx->player_state.direction == LEFT)
		return ((void *)mlx->img_cache.player.m_player_idle[state % 8].addr);
	else
		return ((void *)mlx->img_cache.player.player_idle[state % 8].addr);
}

void	render_idle_player(t_vars *mlx, int x, int y, int fps)
{
	unsigned int	state;

	state = mlx->player_state.state / (fps / 8);
	mlx_put_image_to_window(mlx->mlx, mlx->win, select_idle_img(mlx, state), x, y);
	if (state == 8)
		mlx->player_state.state = 0;
}

void	init_player_state(t_vars *mlx)
{
	mlx->player_state.state = 0;
	mlx->player_state.x = mlx->map->player_x * STATIC_OFFSET;
	mlx->player_state.y = mlx->map->player_y * STATIC_OFFSET;
	mlx->player_state.direction = RIGHT;
}