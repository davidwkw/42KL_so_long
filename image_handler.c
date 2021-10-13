#include "so_long.h"

void	cache_image(void *mlx, t_data *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->img = mlx_get_data_addr(img->addr, &img->bpp, &img->size_line, &img->endian);
}

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
			dst[((y + h) * (img->size_line / 4)) + (x + w)] = src[(h * (asset->size_line / 4)) + w];
	}
}

t_data	*get_static_asset(t_vars *mlx, char c)
{
	if (c == '1')
		return &mlx->img_cache.wall;
	else if (c == 'E')
		return &mlx->img_cache.exit;
	else
		return &mlx->img_cache.bg;
}

void	cache_static_assets(t_vars *mlx)
{
	int	x;
	int	y;

	mlx->img_cache.static_assets.addr = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
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

void	init_images(t_vars *mlx)
{
	cache_image(mlx->mlx, &mlx->img_cache.bg, "assets/dirt.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.wall, "assets/stone.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.exit, "assets/exit.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.coll, "assets/coll.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.player_r1, "assets/player_r1.xpm");
	// cache_image(mlx->mlx, &mlx->img_cache.player_r2, "assets/player_r2.xpm");
	// cache_image(mlx->mlx, &mlx->img_cache.player_l1, "assets/player_l1.xpm");
	// cache_image(mlx->mlx, &mlx->img_cache.player_l2, "assets/player_l2.xpm");
	cache_static_assets(mlx);
}
