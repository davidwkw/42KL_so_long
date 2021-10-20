#include "so_long.h"

void	mlx_handler(t_map *map)
{
	t_vars	mlx;

	mlx = (t_vars){};
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		error_handler("Display var not configured", "main", EIO);
	mlx.map	= map;
	mlx.win_width = map->size_x * STATIC_OFFSET;
	mlx.win_height = map->size_y * STATIC_OFFSET;
	if(mlx.win_width > MAX_WIN_WIDTH)
		mlx.win_width = MAX_WIN_WIDTH;
	if (mlx.win_height > MAX_WIN_HEIGHT)
		mlx.win_height = MAX_WIN_HEIGHT;
	init_images(&mlx);
	init_player_state(&mlx);
	// init_cam();
	printf("Total Steps : %d\n", mlx.total_steps);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height, "So_long");
	mlx_key_hook(mlx.win, key_handler,&mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_program, &mlx);
	mlx_loop(mlx.mlx);
}