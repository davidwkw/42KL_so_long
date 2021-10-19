#include "so_long.h"

void	cache_idle(t_vars *mlx)
{
	t_player_img *player;

	player = &mlx->img_cache.player;
	cache_image(mlx->mlx, &player->player_idle_0, "assets/idle/hero_idle_0.xpm");
	cache_image(mlx->mlx, &player->player_idle_1, "assets/idle/hero_idle_1.xpm");
	cache_image(mlx->mlx, &player->player_idle_2, "assets/idle/hero_idle_2.xpm");
	cache_image(mlx->mlx, &player->player_idle_3, "assets/idle/hero_idle_3.xpm");
	cache_image(mlx->mlx, &player->player_idle_4, "assets/idle/hero_idle_4.xpm");
	cache_image(mlx->mlx, &player->player_idle_5, "assets/idle/hero_idle_5.xpm");
	cache_image(mlx->mlx, &player->player_idle_6, "assets/idle/hero_idle_6.xpm");
	cache_image(mlx->mlx, &player->player_idle_7, "assets/idle/hero_idle_7.xpm");
	cache_mirror_image(mlx->mlx, &player->player_idle_0, &player->m_player_idle_0);
	cache_mirror_image(mlx->mlx, &player->player_idle_1, &player->m_player_idle_1);
	cache_mirror_image(mlx->mlx, &player->player_idle_2, &player->m_player_idle_2);
	cache_mirror_image(mlx->mlx, &player->player_idle_3, &player->m_player_idle_3);
	cache_mirror_image(mlx->mlx, &player->player_idle_4, &player->m_player_idle_4);
	cache_mirror_image(mlx->mlx, &player->player_idle_5, &player->m_player_idle_5);
	cache_mirror_image(mlx->mlx, &player->player_idle_6, &player->m_player_idle_6);
	cache_mirror_image(mlx->mlx, &player->player_idle_7, &player->m_player_idle_7);
}

void	cache_run(t_vars *mlx)
{
	t_player_img *player;

	player = &mlx->img_cache.player;
	cache_image(mlx->mlx, &player->player_run_0, "assets/run/hero_run_0.xpm");
	cache_image(mlx->mlx, &player->player_run_1, "assets/run/hero_run_1.xpm");
	cache_image(mlx->mlx, &player->player_run_2, "assets/run/hero_run_2.xpm");
	cache_image(mlx->mlx, &player->player_run_3, "assets/run/hero_run_3.xpm");
	cache_image(mlx->mlx, &player->player_run_4, "assets/run/hero_run_4.xpm");
	cache_image(mlx->mlx, &player->player_run_5, "assets/run/hero_run_5.xpm");
	cache_image(mlx->mlx, &player->player_run_6, "assets/run/hero_run_6.xpm");
	cache_image(mlx->mlx, &player->player_run_7, "assets/run/hero_run_7.xpm");
	cache_image(mlx->mlx, &player->player_run_8, "assets/run/hero_run_8.xpm");
	cache_image(mlx->mlx, &player->player_run_9, "assets/run/hero_run_9.xpm");
	cache_mirror_image(mlx->mlx, &player->player_run_0, &player->m_player_run_0);
	cache_mirror_image(mlx->mlx, &player->player_run_1, &player->m_player_run_1);
	cache_mirror_image(mlx->mlx, &player->player_run_2, &player->m_player_run_2);
	cache_mirror_image(mlx->mlx, &player->player_run_3, &player->m_player_run_3);
	cache_mirror_image(mlx->mlx, &player->player_run_4, &player->m_player_run_4);
	cache_mirror_image(mlx->mlx, &player->player_run_5, &player->m_player_run_5);
	cache_mirror_image(mlx->mlx, &player->player_run_6, &player->m_player_run_6);
	cache_mirror_image(mlx->mlx, &player->player_run_7, &player->m_player_run_7);
	cache_mirror_image(mlx->mlx, &player->player_run_8, &player->m_player_run_8);
	cache_mirror_image(mlx->mlx, &player->player_run_9, &player->m_player_run_9);
}
