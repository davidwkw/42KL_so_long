#include "so_long.h"

int	render(t_vars *mlx)
{
	struct timeval	tv;
	unsigned long	delay;

	if (!modulate_fps(FPS))
		return (0);
	gettimeofday(&tv, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_cache.static_assets.addr, 0, 0);
	delay = (tv.tv_sec - mlx->last_move_time.tv_sec) * 1000 + (tv.tv_usec - mlx->last_move_time.tv_usec) / 1000;	
	if (delay < ANIM_TRANSITION)
		render_run_player(mlx, FPS);
	else
		render_idle_player(mlx, FPS);
	mlx->player_state.state++;
	display_info(mlx);
	return (0);
}