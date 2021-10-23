#include "so_long.h"

void	*select_idle_img(t_vars *mlx, unsigned int state)
{
	if (mlx->player_state.direction == LEFT)
		return (mlx->img_cache.player.m_player_idle[state].addr);
	else
		return (mlx->img_cache.player.player_idle[state].addr);
}

void	*select_run_img(t_vars *mlx, unsigned int state)
{
	if (mlx->player_state.direction == LEFT)
		return (mlx->img_cache.player.m_player_run[state].addr);
	else
		return (mlx->img_cache.player.player_run[state].addr);
}
