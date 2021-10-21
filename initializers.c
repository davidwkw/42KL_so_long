#include "so_long.h"

// void	init_cam(t_vars *mlx)
// {
// 	if (mlx->img_cache.static_assets.width > mlx->win_width)
// }

void	init_player_state(t_vars *mlx)
{
	mlx->player_state.state = 0;
	mlx->player_state.coords.x = mlx->map->player_coords.x * STATIC_OFFSET;
	mlx->player_state.coords.y = mlx->map->player_coords.y * STATIC_OFFSET;
	mlx->player_state.direction = RIGHT;
}

void	init_images(t_vars *mlx)
{
	cache_image(mlx->mlx, &mlx->img_cache.bg, "assets/dirt.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.wall, "assets/stone.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.exit, "assets/exit.xpm");
	cache_image(mlx->mlx, &mlx->img_cache.coll, "assets/coll.xpm");
	cache_idle(mlx);
	cache_run(mlx);
	cache_static_assets(mlx, &mlx->img_cache.static_assets, 1);
}
