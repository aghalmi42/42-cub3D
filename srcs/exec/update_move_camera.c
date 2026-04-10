#include "../../includes/cub3D.h"

void	update_move_player(t_game *game)
{
	double move = 0.01;
	double	new_x;
	double	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game->move_keys.w)
	{
		new_x += game->player.dir_x * move;
		new_y += game->player.dir_y * move;
	}
	if (game->move_keys.s)
	{
		new_x -= game->player.dir_x * move;
		new_y -= game->player.dir_y * move;
	}
	if (game->move_keys.a)
	{
		new_x -= game->player.plane_x * move;
		new_y -= game->player.plane_y * move;
	}
	if (game->move_keys.d)
	{
		new_x += game->player.plane_x * move;
		new_y += game->player.plane_y * move;
	}
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
	// if(game->move_keys.s && can_move(game, game->player.x, game->player.y - move))
	// 	game->player.y -= move;
	// if(game->move_keys.d && can_move(game, game->player.x, game->player.y + move))
	// 	game->player.y += move;
	// if(game->move_keys.a && can_move(game, game->player.x - move, game->player.y))
	// 	game->player.x -= move;
	// if(game->move_keys.w && can_move(game, game->player.x + move, game->player.y))
	// 	game->player.x += move;
}

void	update_camera_shifting(t_game *game, double shift)
{
	double	last_dir_x = game->player.dir_x;
	double	last_dir_y = game->player.dir_y;

	if (game->move_keys.left)
	{
		game->player.dir_x = last_dir_x * cos(shift) - last_dir_y * sin(shift);
		game->player.dir_y = last_dir_x * sin(shift) + last_dir_y * cos(shift);
		game->player.plane_x = -game->player.dir_y;
		game->player.plane_y = game->player.dir_x;
	}
	if (game->move_keys.right)
	{
		game->player.dir_x = last_dir_x * cos(-shift) - last_dir_y * sin(-shift);
		game->player.dir_y = last_dir_x * sin(-shift) + last_dir_y * cos(-shift);
		game->player.plane_x = -game->player.dir_y;
		game->player.plane_y = game->player.dir_x;
	}
}

int	can_move(t_game *game, double x, double y)
{
	double	collision_dist = 0.2;
	int		check_x;
	int		check_y;

	check_x = (int)(x + collision_dist);
	check_y = (int)(y + collision_dist);
	if (check_x < 0 || check_x >= game->map.width || check_y < 0 || check_y >= game->map.height)
		return (0);
	if (game->map.grid[check_y][check_x] == '1')
		return (0);
	check_x = (int)(x - collision_dist);
	check_y = (int)(y - collision_dist);
	if (check_x < 0 || check_x >= game->map.width || check_y < 0 || check_y >= game->map.height)
		return (0);
	if (game->map.grid[check_y][check_x] == '1')
		return (0);
	return (1);
}