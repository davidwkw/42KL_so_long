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
		{
			if (src[(h * (asset->size_line / (asset->bpp / 8))) + w] != TRANS_INT)
				dst[((y + h) * (img->size_line / (img->bpp / 8))) + (x + w)] = src[(h * (asset->size_line / (asset->bpp / 8))) + w];
		}
	}
}

void	paint_bg(t_vars *mlx, t_data *canvas, t_data *asset, int x, int y)
{
	t_data	shadow;

	shadow.addr = mlx_new_image(mlx->mlx, asset->width, asset->height);
	shadow.width = asset->width;
	shadow.height = asset->height;
	shadow.img = mlx_get_data_addr(shadow.addr, &shadow.bpp, &shadow.size_line, &shadow.endian);
	cache_shadow(asset, &shadow);
	render_bg(mlx, &shadow);
	paint_tile(canvas, x, y, &shadow);
	paint_tile(canvas, x, y, &mlx->img_cache.bg);
	mlx_destroy_image(mlx->mlx, shadow.addr);
}

static t_data	*get_static_asset(t_vars *mlx, char c)
{
	if (c == '1')
		return (&mlx->img_cache.wall);
	else if (c == 'E')
		return (&mlx->img_cache.exit);
	else if (c == 'C')
		return (&mlx->img_cache.coll);
	else
		return &mlx->img_cache.bg;
}

void	cache_static_assets(t_vars *mlx, t_data *canvas, int bg)
{
	int		x;
	int		y;
	t_data	*asset;

	canvas->addr = mlx_new_image(mlx->mlx, mlx->map->size_x * STATIC_OFFSET, mlx->map->size_y * STATIC_OFFSET);
	canvas->width = mlx->map->size_x * STATIC_OFFSET;
	canvas->height = mlx->map->size_y * STATIC_OFFSET;
	canvas->img = mlx_get_data_addr(canvas->addr, &canvas->bpp, &canvas->size_line, &canvas->endian);
	y = -1;
	while (mlx->map->board[++y])
	{
		x = -1;
		while (mlx->map->board[y][++x])
		{
			asset = get_static_asset(mlx, mlx->map->board[y][x]);
			if (bg)
				paint_bg(mlx, canvas, asset, x, y);
			paint_tile(canvas, x, y, asset);
		}
	}
}
