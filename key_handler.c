#include "so_long.h"

static void	undo_move(t_vars *mlx, char move)
{
	if (move == 'a')
		mlx->player_state.coords.x += MOVE_SPEED;
	else if (move == 'd')
		mlx->player_state.coords.x -= MOVE_SPEED;
	else if (move == 'w')
		mlx->player_state.coords.y += MOVE_SPEED;
	else if (move == 's')
		mlx->player_state.coords.y -= MOVE_SPEED;
}

static void	check_win(t_vars *mlx)
{
	if (mlx->map->collectible == 0)
		printf("You win !\n");
	else
		printf("There are %d collectibles left !\n", mlx->map->collectible);
}

static void	check_collision(t_vars *mlx, char move)
{
	int		x;
	int 	y;
	char	top_left;
	char	top_right; // move these vars into player coords
	char	bottom_left;
	char	bottom_right;

	x = mlx->player_state.coords.x;
	y = mlx->player_state.coords.y;
	top_left = mlx->map->ss_board[y + 14][x + 40];
	top_right = mlx->map->ss_board[y + 14][x + mlx->img_cache.player.player_run->width - 50];
	bottom_left = mlx->map->ss_board[y + mlx->img_cache.player.player_run->height - 2][x + 40];
	bottom_right = mlx->map->ss_board[y + mlx->img_cache.player.player_run->height - 2][x + mlx->img_cache.player.player_run->width - 50];
	if (top_left == '1' || bottom_right == '1' || top_right == '1' || bottom_left == '1')
		undo_move(mlx, move);
	else if (top_left == 'C' || bottom_right == 'C' || top_right == 'C' || bottom_left == 'C')
	{
		paint_tile(&mlx->img_cache.static_assets, (x + 80) / 100, (y + 80) / 100, &mlx->img_cache.bg);
		// mlx->map->board[y][x] = '0';
		mlx->map->collectible--;
	}
	else if (top_left == 'E' || bottom_right == 'E' || top_right == 'E' || bottom_left == 'E')
		check_win(mlx);
}

void	movement_handler(int keycode, t_vars *mlx)
{
	gettimeofday(&mlx->last_move_time, NULL);
	if (keycode == 'a')
	{
		mlx->player_state.coords.x -= MOVE_SPEED;
		mlx->player_state.direction = LEFT;
	}
	else if (keycode == 'd')
	{
		mlx->player_state.coords.x += MOVE_SPEED;
		mlx->player_state.direction = RIGHT;
	}
	else if (keycode == 'w')
		mlx->player_state.coords.y -= MOVE_SPEED;
	else if (keycode == 's')
		mlx->player_state.coords.y += MOVE_SPEED;
	mlx->total_steps++;
	mlx->player_state.state++;
	check_collision(mlx, keycode);
	printf("Total steps : %d\n", mlx->total_steps);
}

int	key_handler(int key, t_vars *mlx)
{
	if (key == 65307)
		exit_program(mlx);
	else if (ft_strchr("wasd", key))
		movement_handler(key, mlx);
	return (0);
}