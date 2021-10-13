#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		printf("Usage: %s [<MAP_NAME>.ber]\n", argv[0]);
	parse_map(argv[1], &map);
	mlx_handler(&map);
	return (0);
}