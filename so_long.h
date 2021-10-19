
#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"

# define STATIC_OFFSET 100
# define LEFT 0
# define RIGHT 1
# define FPS 30
# define IDLE_FRAMES 8
# define RUN_FRAMES 10

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

typedef struct	s_player_img
{
	t_data	player_idle[IDLE_FRAMES];
	t_data	m_player_idle[IDLE_FRAMES];
	t_data	player_run[RUN_FRAMES];
	t_data	m_player_run[RUN_FRAMES];
}	t_player_img;

typedef struct	s_player_state
{
	int				state;
	unsigned int	direction : 1;
	int				x;
	int				y;
}	t_player_state;

typedef struct	s_imgs 
{
	t_data			bg;
	t_player_img	player;
	t_data			coll;
	t_data			wall;
	t_data			exit;
	t_data			static_assets;
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
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	t_imgs			img_cache;
	t_player_state	player_state;
	t_map			*map;
}	t_vars;

void	error_handler(char *msg, char *func, int err_no);

void	check_tb_border(char *line);
void	check_map_content(char *line, t_map *map, size_t y);

void	check_valid_ext(char *filename, char *ext_to_check);
void	parse_map(char *filename, t_map *map);

void	init_images(t_vars *mlx);
void	init_player_state(t_vars *mlx);
void	mlx_handler(t_map *map);
int		render(t_vars *mlx);
void	render_bg(t_vars *mlx, t_data *img);
void	render_idle_player(t_vars *mlx, int x, int y, int fps);
void	render_collectible();

void	cache_static_assets(t_vars *mlx);
void	cache_idle(t_vars *mlx);
void	cache_run(t_vars *mlx);

void	cache_image(void *mlx, t_data *img, char *path);
void	cache_mirror_image(void *mlx, t_data *img, t_data *mirror);

int		arr_len(char **arr);

#endif