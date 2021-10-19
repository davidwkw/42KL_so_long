#include "so_long.h"

void	*select_idle_img(t_vars *mlx, unsigned int state)
{
	const void	*img[] = {
		mlx->img_cache.player.player_idle_0.addr,
		mlx->img_cache.player.player_idle_1.addr,
		mlx->img_cache.player.player_idle_2.addr,
		mlx->img_cache.player.player_idle_3.addr,
		mlx->img_cache.player.player_idle_4.addr,
		mlx->img_cache.player.player_idle_5.addr,
		mlx->img_cache.player.player_idle_6.addr,
		mlx->img_cache.player.player_idle_7.addr
	};
	const void	*m_img[] = {
		mlx->img_cache.player.m_player_idle_0.addr,
		mlx->img_cache.player.m_player_idle_1.addr,
		mlx->img_cache.player.m_player_idle_2.addr,
		mlx->img_cache.player.m_player_idle_3.addr,
		mlx->img_cache.player.m_player_idle_4.addr,
		mlx->img_cache.player.m_player_idle_5.addr,
		mlx->img_cache.player.m_player_idle_6.addr,
		mlx->img_cache.player.m_player_idle_7.addr
	};

	if (mlx->player_state.direction == LEFT)
		return ((void *)m_img[state % 8]);
	else
		return ((void *)img[state % 8]);
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