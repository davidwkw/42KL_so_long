#include "so_long.h"

static void	check_side_border(char c)
{
	if (c != '1')
		error_handler("Vertical border not intact", "check_side_border", EIO);
}

void	parse_map_items(char c, t_map *map, int x)
{
	if (c == 'P')
	{
		map->player++;
		if (map->player > 1)
			error_handler("More than 1 player", "parse_map_items", EIO);
		map->player_x = x;
		map->player_y = map->size_y;
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

void	check_map_content(char *line, t_map *map)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (i == 0 || i == (ft_strlen(line) - 1))
			check_side_border(line[i]);
		else if (ft_strchr("01CEP", line[i]))
			parse_map_items(line[i], map, i);
		else
			error_handler("Invalid map item", "check_map_content", EIO);
		i++;
	}
}
