#include "so_long.h"

void	init_images(t_vars *mlx)
{
	cache_image(mlx->mlx, &mlx->img_cache.bg, "assets/dirt.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.wall, "assets/stone.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.exit, "assets/exit.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.coll, "assets/coll.xpm");
	cache_idle(mlx);
	cache_run(mlx);
	cache_static_assets(mlx);
}
