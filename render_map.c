#include "so_long.h"

// void	render_static_assets(t_vars *mlx, char c, int x, int y)
// {
// 	if (c == '1')
// 		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_cache.wall.addr, x, y);
// 	else if (c == 'E')
// 		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_cache.exit.addr, x, y);
// 	else
// 		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_cache.bg.addr, x, y);
// }

// void	render_map(t_vars *mlx)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (map->board[++y])
// 	{
// 		x = -1;
// 		while (map->board[y][++x])
// 		{
// 			render_static_assets(mlx, map->board[y][x], x * STATIC_OFFSET, y * STATIC_OFFSET);
// 		}
// 	}
// }

// void	set_tile(int *img, x, y, int *asset)
// {
// 	w = -1;
// 	while (++w < asset.width)
// 	{
// 		h = -1
// 		while (++h < asset.height)
// 		{
// 			img[(y + h) * (size_line/4) + (x + w)] = asset[h * (asset.size_len/4) + w];
// 		}
// 	}
// }
