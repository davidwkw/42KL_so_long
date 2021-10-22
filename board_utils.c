#include "so_long.h"

void	upscale_board(t_map *map, char ***ss_board)
{
	size_t	x;
	size_t	y;
	size_t	i;
	size_t 	j;

	// *ss_board = (char **)malloc(sizeof(char *) * ((map->size_y * STATIC_OFFSET) + (map->size_y * STATIC_OFFSET * map->size_x * STATIC_OFFSET)));
	// y = -1;
	// while (++y < map->size_y * STATIC_OFFSET)
	// 	(*ss_board)[y] = (char *)(ss_board + (map->size_y * STATIC_OFFSET)) + (map->size_x * STATIC_OFFSET * y);
	*ss_board = malloc(sizeof(char *) * (map->size_y * STATIC_OFFSET));
	y = -1;
	while (++y < map->size_y * STATIC_OFFSET)
		(*ss_board)[y] = malloc(sizeof(char) * (map->size_x * STATIC_OFFSET));
	y = -1;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x < map->size_x)
		{
			j = -1;
			while (++j < STATIC_OFFSET)
			{
				i = -1;
				while (++i < STATIC_OFFSET)
					(*ss_board)[(y * STATIC_OFFSET) + j][(x * STATIC_OFFSET) + i] = map->board[y][x];
			}	
		}
	}
}


void	super_sample_board(t_vars *mlx)
{
	int		w;
	int		h;
	int		*src;
	t_data	img;
	int		pixel_color;

	upscale_board(mlx->map, &mlx->ss_board);
	cache_static_assets(mlx, &img, 0);
	src = (int *)img.img;
	h = -1;
	while (++h < img.height)
	{
		w = -1;
		while (++w < img.width)
		{
			pixel_color = src[w + (h * (img.size_line / (img.bpp / 8)))];
			if (pixel_color == TRANS_INT)
				mlx->ss_board[h][w] = '0';
		}
	}
	mlx_destroy_image(mlx->mlx, img.addr);
}
