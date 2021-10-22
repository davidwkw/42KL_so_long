#include "so_long.h"

void	set_bg(char *c)
{
	*c = '0';
}

void	set_player(char *c)
{
	*c = 'p';
}

void	map_player(t_vars *mlx, int p_x, int p_y, void (*func)(char *c))
{
	int	w;
	int	h;
	int	x;
	int y;

	w = p_x + P_WIDTH;
	h = p_y + P_HEIGHT;
	x = p_x;
	y = p_y;
	while (x < w)
	{
		while (y < h)
		{
			func(&mlx->ss_board[y][x]);
			y++;
		}
		x++;
	}
}
