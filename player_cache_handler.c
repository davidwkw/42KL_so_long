#include "so_long.h"

static void mirror_img(t_vars *mlx, t_data player[], t_data m_player[], int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		cache_mirror_image(mlx->mlx, &player[i], &m_player[i]);
		i++;
	}
}

void	cache_idle(t_vars *mlx)
{
	t_player_img 	*player;
	unsigned int	frames;

	player = &mlx->img_cache.player;
	frames = sizeof(player->player_idle) / sizeof(*player->player_idle);
	cache_image(mlx->mlx, &player->player_idle[0], "assets/idle/hero_idle_0.xpm");
	cache_image(mlx->mlx, &player->player_idle[1], "assets/idle/hero_idle_1.xpm");
	cache_image(mlx->mlx, &player->player_idle[2], "assets/idle/hero_idle_2.xpm");
	cache_image(mlx->mlx, &player->player_idle[3], "assets/idle/hero_idle_3.xpm");
	cache_image(mlx->mlx, &player->player_idle[4], "assets/idle/hero_idle_4.xpm");
	cache_image(mlx->mlx, &player->player_idle[5], "assets/idle/hero_idle_5.xpm");
	cache_image(mlx->mlx, &player->player_idle[6], "assets/idle/hero_idle_6.xpm");
	cache_image(mlx->mlx, &player->player_idle[7], "assets/idle/hero_idle_7.xpm");
	mirror_img(mlx, player->player_idle, player->m_player_idle, frames);
}

void	cache_run(t_vars *mlx)
{
	t_player_img 	*player;
	unsigned int	frames;

	player = &mlx->img_cache.player;
	frames = sizeof(player->player_run) / sizeof(*player->player_run);
	cache_image(mlx->mlx, &player->player_run[0], "assets/run/hero_run_0.xpm");
	cache_image(mlx->mlx, &player->player_run[1], "assets/run/hero_run_1.xpm");
	cache_image(mlx->mlx, &player->player_run[2], "assets/run/hero_run_2.xpm");
	cache_image(mlx->mlx, &player->player_run[3], "assets/run/hero_run_3.xpm");
	cache_image(mlx->mlx, &player->player_run[4], "assets/run/hero_run_4.xpm");
	cache_image(mlx->mlx, &player->player_run[5], "assets/run/hero_run_5.xpm");
	cache_image(mlx->mlx, &player->player_run[6], "assets/run/hero_run_6.xpm");
	cache_image(mlx->mlx, &player->player_run[7], "assets/run/hero_run_7.xpm");
	cache_image(mlx->mlx, &player->player_run[8], "assets/run/hero_run_8.xpm");
	cache_image(mlx->mlx, &player->player_run[9], "assets/run/hero_run_9.xpm");
	mirror_img(mlx, player->player_run, player->m_player_run, frames);
}
