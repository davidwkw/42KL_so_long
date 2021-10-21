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
			if (dst[(h * img->size_line / (img->bpp / 8)) + w] == TRANS_INT)
				dst[(h * (img->size_line / (img->bpp / 8))) + w] = src[(h * (mlx->img_cache.bg.size_line / (mlx->img_cache.bg.bpp / 8))) + w];
		}
	}
}
