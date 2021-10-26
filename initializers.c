#include "so_long.h"

void	init_cam(t_vars *mlx, t_cam *cam, t_data *canvas)
{
	*cam = (t_cam){.w_coords.x = 0, .w_coords.y = 0};
	cam->max_x_offset = canvas->width - mlx->win_width;
	cam->max_y_offset = canvas->height - mlx->win_height;
}

void	init_player_state(t_p_state *player_state, t_map *map, t_p_imgs *player)
{
	*player_state = (t_p_state){.state = 0};
	gettimeofday(&player_state->last_move_time, NULL);
	player_state->coords.x = map->player_coords.x * STATIC_OFFSET;
	player_state->coords.y = map->player_coords.y * STATIC_OFFSET;
	calc_offsets(&player->player_idle[0], &player_state->offsets);
	player_state->direction = RIGHT;
}

void	init_images(t_vars *mlx, void *p_mlx, t_imgs *cache)
{
	cache_image(p_mlx, &cache->bg, "assets/dirt.xpm");
	// cache_image(p_mlx, &cache->bg, "assets/floor2.xpm");
	cache_image(p_mlx, &cache->wall, "assets/stone.xpm");
	cache_image(p_mlx, &cache->exit, "assets/exit.xpm");
	cache_image(p_mlx, &cache->coll, "assets/coll.xpm");
	cache_idle(mlx->mlx, &cache->player);
	cache_run(mlx->mlx, &cache->player);
	cache_static_assets(mlx, &cache->static_assets, 1);
}