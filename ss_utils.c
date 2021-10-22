#include "so_long.h"

static void offset_p_top(t_vars *mlx)
{
	int	x;
	int	y;
	int p_x;
	int	p_y;

	p_x = mlx->player_state.coords.x;
	p_y = mlx->player_state.coords.y;
	y = -1;
	while (++y < P_TOP_OFFSET)
	{
		x = -1;
		while (++x < STATIC_OFFSET)
			mlx->ss_board[p_y + y][p_x + x] = '0';
	}
}

static void offset_p_left(t_vars *mlx)
{
	int	x;
	int	y;
	int p_x;
	int	p_y;

	p_x = mlx->player_state.coords.x;
	p_y = mlx->player_state.coords.y;
	y = -1;
	while (++y < STATIC_OFFSET)
	{
		x = -1;
		while (++x < P_LEFT_OFFSET)
			mlx->ss_board[p_y + y][p_x + x] = '0';
	}
}

static void offset_p_right(t_vars *mlx)
{
	int	x;
	int	y;
	int p_x;
	int	p_y;

	p_x = mlx->player_state.coords.x;
	p_y = mlx->player_state.coords.y;
	y = -1;
	while (++y < STATIC_OFFSET)
	{
		x = STATIC_OFFSET - P_RIGHT_OFFSET - 1;
		while (++x < STATIC_OFFSET)
			mlx->ss_board[p_y + y][p_x + x] = '0';
	}
}

static void offset_p_bottom(t_vars *mlx)
{
	int	x;
	int	y;
	int p_x;
	int	p_y;

	p_x = mlx->player_state.coords.x;
	p_y = mlx->player_state.coords.y;
	y = STATIC_OFFSET - P_IMG_HEIGHT - P_BOTTOM_OFFSET;
	while (++y < STATIC_OFFSET)
	{
		x = -1;
		while (++x < STATIC_OFFSET)
			mlx->ss_board[p_y + y][p_x + x] = '0';
	}
}

void super_sample_player(t_vars *mlx)
{
	offset_p_top(mlx);
	offset_p_left(mlx);
	offset_p_right(mlx);
	offset_p_bottom(mlx);
	mlx->player_state.coords.x += P_LEFT_OFFSET;
	mlx->player_state.coords.y += P_TOP_OFFSET;
}