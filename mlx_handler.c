#include "so_long.h"

void	mlx_handler(t_map *map)
{
	t_vars	mlx;

	mlx.map	= map;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		error_handler("Display var not configured", "main", EIO);
	mlx.win_width = map->size_x * STATIC_OFFSET;
	mlx.win_height = map->size_y * STATIC_OFFSET;
	init_images(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height, "So_long");
	// hooks here
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img_cache.static_assets.addr, 0, 0);
	// mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_loop(mlx.mlx);
}