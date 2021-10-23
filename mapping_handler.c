#include "so_long.h"

void	map_player(char ***ss_board, int p_x, int p_y, char c)
{
	int	w;
	int	h;
	int	x;
	int y;

	w = p_x + P_WIDTH;
	h = p_y + P_HEIGHT;
	y = p_y;
	while (y < h)
	{
		x = p_x;
		while (x < w)
		{
			(*ss_board)[y][x] = c;
			x++;
		}
		y++;
	}
}

void	map_tile(char ***ss_board, int origin_x, int origin_y, char c)
{
	int	w;
	int	h;
	int	x;
	int y;

	w = origin_x + STATIC_OFFSET;
	h = origin_y + STATIC_OFFSET;
	y = origin_y;
	while (y < h)
	{
		x = origin_x;
		while (x < w)
		{
			(*ss_board)[y][x] = c;
			x++;
		}
		y++;
	}
}

void	locate_collision(char ***ss_board,  int p_x, int p_y, int *coll_x, int *coll_y)
{
	int x;
	int y;
	int w;
	int	h;

	h = p_y + P_HEIGHT;
	w = p_x + P_WIDTH;
	y = p_y;
	while (y < h)
	{
		x = p_x;
		while (x < w)
		{
			if ((*ss_board)[y][x] == 'C')
			{
				*coll_x = x;
				*coll_y = y;
			}
			x++;
		}
		y++;
	}
}
