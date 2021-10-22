#include "so_long.h"

void	render_run_player(t_vars *mlx, int fps)
{
	unsigned int	state;
	t_player_img 	*player;
	unsigned int	frames;
	int				x;
	int				y;

	player = &mlx->img_cache.player;
	frames = sizeof(player->player_run) / sizeof(*player->player_run);
	state = mlx->player_state.state / (fps / frames);
	x = mlx->player_state.coords.x - P_LEFT_OFFSET;
	y = mlx->player_state.coords.y - P_TOP_OFFSET;
	mlx_put_image_to_window(mlx->mlx, mlx->win, select_run_img(mlx, state % frames), x, y);
	if (state == frames)
		mlx->player_state.state = 0;
}

void	render_idle_player(t_vars *mlx, int fps)
{
	unsigned int	state;
	t_player_img 	*player;
	unsigned int	frames;
	int				x;
	int				y;

	player = &mlx->img_cache.player;
	frames = sizeof(player->player_idle) / sizeof(*player->player_idle);
	state = mlx->player_state.state / (fps / frames);
	x = mlx->player_state.coords.x - P_LEFT_OFFSET;
	y = mlx->player_state.coords.y - P_TOP_OFFSET;
	mlx_put_image_to_window(mlx->mlx, mlx->win, select_idle_img(mlx, state % frames), x, y);
	if (state == frames)
		mlx->player_state.state = 0;
}
