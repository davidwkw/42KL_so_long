#include <sys/time.h>
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
	if (!modulate_fps(FPS))
		return (0);
	render_idle_player(mlx, mlx->player_state.x, mlx->player_state.y, FPS);
	// render_collectible();
	mlx->player_state.state++;
	return (0);
}
