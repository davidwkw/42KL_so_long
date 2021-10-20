#include "so_long.h"

void	paint_tile(t_data *img, int x, int y, t_data *asset)
{
	int w;
	int	h;
	int *src;
	int	*dst;

	src = (int *)asset->img;
	dst = (int *)img->img;
	x *= STATIC_OFFSET;
	y *= STATIC_OFFSET;
	h = -1;
	while (++h < asset->height)
	{
		w = -1;
		while (++w < asset->width)
			dst[((y + h) * (img->size_line / (img->bpp / 8))) + (x + w)] = src[(h * (asset->size_line / (asset->bpp / 8))) + w];
	}
}

static t_data	*get_static_asset(t_vars *mlx, char c)
{
	if (c == '1')
	{
		render_bg(mlx, &mlx->img_cache.wall);
		return (&mlx->img_cache.wall);
	}
	else if (c == 'E')
	{
		render_bg(mlx, &mlx->img_cache.exit);
		return (&mlx->img_cache.exit);
	}
	else if (c == 'C')
	{
		render_bg(mlx, &mlx->img_cache.coll);
		return (&mlx->img_cache.coll);
	}
	else
		return &mlx->img_cache.bg;
}

void	cache_static_assets(t_vars *mlx)
{
	int	x;
	int	y;

	mlx->img_cache.static_assets.addr = mlx_new_image(mlx->mlx, mlx->map->size_x * STATIC_OFFSET, mlx->map->size_y * STATIC_OFFSET);
	mlx->img_cache.static_assets.img = mlx_get_data_addr(mlx->img_cache.static_assets.addr, &mlx->img_cache.static_assets.bpp, &mlx->img_cache.static_assets.size_line, &mlx->img_cache.static_assets.endian);
	y = -1;
	while (mlx->map->board[++y])
	{
		x = -1;
		while (mlx->map->board[y][++x])
		{
			paint_tile(&mlx->img_cache.static_assets, x, y, &mlx->img_cache.bg);
			paint_tile(&mlx->img_cache.static_assets, x, y, get_static_asset(mlx, mlx->map->board[y][x]));
		}
	}
}