#include "so_long.h"

void	collection_handler(t_vars *mlx, int x, int y)
{
	int	coll_x;
	int	coll_y;

	locate_p_collision(&mlx->ss_board, x, y, &coll_x, &coll_y, 'C');
	map_tile(&mlx->ss_board, (coll_x / 100) * 100, (coll_y / 100) * 100, '0');
	paint_tile(&mlx->img_cache.static_assets, coll_x / 100, coll_y / 100, &mlx->img_cache.bg);
	mlx->map->collectible--;
}