#include "so_long.h"

static void	undo_move(t_vars *mlx, char move)
{
	if (move == 'a')
		mlx->player_state.coords.x += 20;
	else if (move == 'd')
		mlx->player_state.coords.x -= 20;
	else if (move == 'w')
		mlx->player_state.coords.y += 20;
	else if (move == 's')
		mlx->player_state.coords.y -= 20;
}

static void	check_win(t_vars *mlx)
{
	if (mlx->map->collectible == 0)
	{
		printf("You win !\n");

	}
	else
		printf("There are %d collectibles left !\n", mlx->map->collectible);
}

static void	check_collision(t_vars *mlx, char move)
{
	int x;
	int y;

	x = mlx->player_state.coords.x / 100;
	y = mlx->player_state.coords.y / 100;
	if (mlx->map->board[y][x] == '1')
		undo_move(mlx, move);
	else if (mlx->map->board[y][x] == 'C')
	{
		paint_tile(&mlx->img_cache.static_assets, x, y, &mlx->img_cache.bg);
		mlx->map->board[y][x] = '0';
		mlx->map->collectible--;
	}
	else if (mlx->map->board[y][x] == 'E')
		check_win(mlx);
}

void	movement_handler(int keycode, t_vars *mlx)
{
	gettimeofday(&mlx->last_move_time, NULL);
	if (keycode == 'a')
	{
		mlx->player_state.coords.x -= 20;
		mlx->player_state.direction = LEFT;
	}
	else if (keycode == 'd')
	{
		mlx->player_state.coords.x += 20;
		mlx->player_state.direction = RIGHT;
	}
	else if (keycode == 'w')
		mlx->player_state.coords.y -= 20;
	else if (keycode == 's')
		mlx->player_state.coords.y += 20;
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