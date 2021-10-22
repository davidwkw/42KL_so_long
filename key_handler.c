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

static void	check_p_collision(t_vars *mlx, char move)
{
	int		x;
	int 	y;

	x = mlx->player_state.coords.x;
	y = mlx->player_state.coords.y;
	if (is_oob(mlx, x, y) || check_p_map(mlx, '1', x, y))
		undo_move(mlx, move);
	else if (check_p_map(mlx, 'C', x, y))
	{
		paint_tile(&mlx->img_cache.static_assets, (x + 80) / 100, (y + 80) / 100, &mlx->img_cache.bg);
		// mlx->map->board[y][x] = '0';
		mlx->map->collectible--;
	}
	else if (check_p_map(mlx, 'E', x, y))
		check_win(mlx);
}

void	movement_handler(int keycode, t_vars *mlx)
{
	gettimeofday(&mlx->last_move_time, NULL);
	if (keycode == 'a')
	{
		mlx->player_state.direction = LEFT;
		mlx->player_state.coords.x -= MOVE_SPEED;
	}
	else if (keycode == 'd')
	{
		mlx->player_state.direction = RIGHT;
		mlx->player_state.coords.x += MOVE_SPEED;
	}
	else if (keycode == 'w')
		mlx->player_state.coords.y -= MOVE_SPEED;
	else if (keycode == 's')
		mlx->player_state.coords.y += MOVE_SPEED;
	mlx->total_steps++;
	mlx->player_state.state++;
	check_p_collision(mlx, keycode);
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