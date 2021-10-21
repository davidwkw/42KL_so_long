#include "so_long.h"

static void	check_side_border(char c)
{
	if (c != '1')
		error_handler("Vertical border not intact", "check_side_border", EIO);
}

void	parse_map_items(char c, t_map *map, int x, int y)
{
	if (c == 'P')
	{
		map->player++;
		if (map->player > 1)
			error_handler("More than 1 player", "parse_map_items", EIO);
		map->player_coords.x = x;
		map->player_coords.y = y;
	}
	else if (c == 'C')
		map->collectible++;
	else if (c == 'E')
		map->exit++;
}

void check_tb_border(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '1')
			error_handler("Horizontal border not intact", "check_tb_border", EIO);
		i++;
	}
}

void	check_map_content(char *line, t_map *map, size_t y)
{
	size_t	x;

	x = 0;
	while (line[x])
	{
		if (x == 0 || x == (ft_strlen(line) - 1))
			check_side_border(line[x]);
		else if (ft_strchr("01CEP", line[x]))
			parse_map_items(line[x], map, x, y);
		else
			error_handler("Invalid map item", "check_map_content", EIO);
		x++;
	}
}

void	super_sample_board(t_vars *mlx)
{
	int		w;
	int		h;
	int		*src;
	t_data	img;
	int		pixel_color;

	cache_static_assets(mlx, &img, 0);
	src = (int *)img.img;
	h = -1;
	while (++h < img.height)
	{
		w = -1;
		while (++w < img.width)
		{
			pixel_color = src[w + (h * (img.size_line / (img.bpp / 8)))];
			if (pixel_color == TRANS_INT || pixel_color == 0)
				mlx->map->ss_board[h][w] = '0';
		}
	}
	mlx_destroy_image(mlx->mlx, img.addr);
}
