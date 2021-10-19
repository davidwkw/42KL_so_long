#include "so_long.h"

void	mlx_handler(t_map *map)
{
	t_vars	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		error_handler("Display var not configured", "main", EIO);
	mlx.map	= map;
	mlx.win_width = map->size_x * STATIC_OFFSET;
	mlx.win_height = map->size_y * STATIC_OFFSET;
	if(mlx.win_width > 1920)
		mlx.win_width = 1920;
	if (mlx.win_height > 1080)
		mlx.win_height = 1080;
	init_images(&mlx);
	init_player_state(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height, "So_long");
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img_cache.static_assets.addr, 0, 0);
	mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_loop(mlx.mlx);
}