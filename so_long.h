
#ifndef SO_LONG_H

# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"

# define STATIC_OFFSET 100

# define LEFT 0
# define RIGHT 1

# define FPS 30
# define IDLE_FRAMES 8
# define RUN_FRAMES 10

# define MAX_WIN_HEIGHT 760
# define MAX_WIN_WIDTH 1900

# define ANIM_TRANSITION 240
# define MOVE_SPEED 20

# define TRANS_INT -16777216

# define P_IMG_WIDTH 100
# define P_IMG_HEIGHT 55
# define P_TOP_OFFSET 13
# define P_LEFT_OFFSET 38
# define P_RIGHT_OFFSET 38
# define P_BOTTOM_OFFSET 2
# define P_WIDTH (P_IMG_WIDTH - P_LEFT_OFFSET - P_RIGHT_OFFSET)
# define P_HEIGHT (P_IMG_HEIGHT - P_TOP_OFFSET - P_BOTTOM_OFFSET)

typedef struct	s_offsets
{
	int	top;
	int	left;
	int	right;
	int	bottom;
}	t_offsets;

typedef struct	s_data
{
	void		*addr;
	char		*img;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}	t_data;

typedef struct	s_player_img
{
	t_data		player_idle[IDLE_FRAMES];
	t_data		m_player_idle[IDLE_FRAMES];
	t_data		player_run[RUN_FRAMES];
	t_data		m_player_run[RUN_FRAMES];
}	t_player_img;

typedef struct	s_imgs 
{
	t_data			bg;
	t_player_img	player;
	t_data			coll;
	t_data			wall;
	t_data			exit;
	t_data			static_assets;
}	t_imgs;

typedef struct	s_coords
{
	int	x;
	int y;
}	t_coords;

typedef struct	s_player_state
{
	int				state;
	unsigned int	direction : 1;
	t_coords		coords;
	t_offsets		offsets;
}	t_player_state;

typedef struct	s_map
{
	char			**board;
	int				steps;
	size_t			size_x;
	size_t			size_y;
	unsigned int	collectible;
	int				player;
	t_coords		player_coords;
	int				exit;
	char			**ss_board;
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
	struct timeval	last_move_time;
	t_coords		cam;
	unsigned int	total_steps;
	char			**ss_board;
}	t_vars;

// error_handler.c
void	error_handler(char *msg, char *func, int err_no);

//map_utils.c
void	check_tb_border(char *line);
void	check_map_content(char *line, t_map *map, size_t y);

// file_validator.c
void	check_valid_ext(char *filename, char *ext_to_check);
void	parse_map(char *filename, t_map *map);

// initializers.c
void	init_images(t_vars *mlx);
void	init_player_state(t_vars *mlx);

// mlx_handler.c
void	mlx_handler(t_map *map);

// render_utils.c
void	render_bg(t_vars *mlx, t_data *img);

// render.c
int		render(t_vars *mlx);

// player_handler.c
void	render_idle_player(t_vars *mlx, int fps);
void	render_run_player(t_vars *mlx, int fps);

// dynamic_asset_handler.c
void	render_collectibles(t_vars *mlx);

// static_cache_handler.c
void	cache_static_assets(t_vars *mlx, t_data *canvas, int bg);
void	paint_tile(t_data *img, int x, int y, t_data *asset);

// player_cache_handler.c
void	cache_idle(t_vars *mlx);
void	cache_run(t_vars *mlx);

// cache_utils.c
void	cache_image(void *mlx, t_data *img, char *path);
void	cache_mirror_image(void *mlx, t_data *img, t_data *mirror);
void	cache_shadow(t_data *obj, t_data *shadow);

// key_handler.c
int	key_handler(int key, t_vars *mlx);

// utils.c
int		arr_len(char **arr);
int		exit_program(t_vars *mlx);
int		modulate_fps(int fps);
void	display_info(t_vars *mlx);

// image_selector.c
void	*select_idle_img(t_vars *mlx, unsigned int state);
void	*select_run_img(t_vars *mlx, unsigned int state);

// offset_handler.c
void	calc_offsets(t_data *img, t_offsets *offset);

// ss_utils.c
void	super_sample_player(t_vars *mlx);

// ss_handler.c
void	super_sample_board(t_vars *mlx);

// movement_utils.c
int	check_p_map(t_vars *mlx, char obj, int p_x, int p_y);
int	is_oob(t_vars *mlx, int x, int y);

#endif