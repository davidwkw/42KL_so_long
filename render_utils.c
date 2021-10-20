#include "so_long.h"

void	render_bg(t_vars *mlx, t_data *img)
{
	int w;
	int	h;
	int *src;
	int	*dst;

	src = (int *)mlx->img_cache.bg.img;
	dst = (int *)img->img;
	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (dst[(h * img->size_line / 4) + w] == 1)
				dst[(h * (img->size_line / 4)) + w] = src[(h * (mlx->img_cache.bg.size_line / 4)) + w];
		}
	}
}

int	modulate_fps(int fps)
{
	struct timeval	tv;
	static struct timeval prev;

	gettimeofday(&tv, NULL);
	if (tv.tv_sec == prev.tv_sec && (tv.tv_usec - prev.tv_usec) < (1000000 / fps))
		return (0);
	prev = tv;
	return (1);
}

int	render(t_vars *mlx)
{
	struct timeval	tv;
	unsigned long	delay;
	char			*steps_str;
	char			*steps;

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
	steps = ft_itoa(mlx->total_steps);
	steps_str = ft_strjoin("Total steps : ", steps);
	mlx_string_put(mlx->mlx, mlx->win, 0, mlx->win_height - 30, 0x00FFFFFF, steps_str);
	free(steps);
	free(steps_str);
	return (0);
}
