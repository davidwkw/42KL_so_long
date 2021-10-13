
#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"

# define STATIC_OFFSET 100

typedef struct	s_data
{
	void	*addr;
	char	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct	s_imgs 
{
	t_data	bg;
	t_data	player_r1;
	t_data	player_r2;
	t_data	player_l1;
	t_data	player_l2;
	t_data	coll;
	t_data	wall;
	t_data	exit;
	t_data	static_assets;
}	t_imgs;

typedef struct	s_map
{
	char	**board;
	int		steps;
	size_t	size_x;
	size_t	size_y;
	int		collectible;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_imgs	img_cache;
	t_map	*map;
}	t_vars;

void	error_handler(char *msg, char *func, int err_no);

void	check_tb_border(char *line);
void	check_map_content(char *line, t_map *map);

void	check_valid_ext(char *filename, char *ext_to_check);
void	parse_map(char *filename, t_map *map);

void	init_images(t_vars *mlx);
void	mlx_handler(t_map *map);
void	render_map(t_vars *mlx, t_map *map);

int		arr_len(char **arr);

#endif