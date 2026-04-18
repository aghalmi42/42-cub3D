/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_move_camera_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:54:59 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:00 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

void	update_move_player(t_game *game)
{
	double	move;
	double	new_x;
	double	new_y;

	move = 0.01;
	new_x = game->player.x;
	new_y = game->player.y;
	update_new_coords(&new_x, &new_y, game, move);
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	update_new_coords(double *new_x, double *new_y,
		t_game *game, double move)
{
	if (game->move_keys.w)
	{
		*new_x = *new_x + game->player.dir_x * move;
		*new_y = *new_y + game->player.dir_y * move;
	}
	if (game->move_keys.s)
	{
		*new_x = *new_x - game->player.dir_x * move;
		*new_y = *new_y - game->player.dir_y * move;
	}
	if (game->move_keys.a)
	{
		*new_x = *new_x - game->player.plane_x * move;
		*new_y = *new_y - game->player.plane_y * move;
	}
	if (game->move_keys.d)
	{
		*new_x = *new_x + game->player.plane_x * move;
		*new_y = *new_y + game->player.plane_y * move;
	}
}

void	update_camera_shifting(t_game *game, double shift)
{
	double	last_dir_x;
	double	last_dir_y;

	last_dir_y = game->player.dir_y;
	last_dir_x = game->player.dir_x;
	if (game->move_keys.left)
	{
		game->player.dir_x = last_dir_x * cos(shift) - last_dir_y * sin(shift);
		game->player.dir_y = last_dir_x * sin(shift) + last_dir_y * cos(shift);
		game->player.plane_x = -game->player.dir_y;
		game->player.plane_y = game->player.dir_x;
	}
	if (game->move_keys.right)
	{
		game->player.dir_x = last_dir_x * cos(-shift)
			- last_dir_y * sin(-shift);
		game->player.dir_y = last_dir_x * sin(-shift)
			+ last_dir_y * cos(-shift);
		game->player.plane_x = -game->player.dir_y;
		game->player.plane_y = game->player.dir_x;
	}
}

static	int	is_solid(t_game *game, double x, double y)
{
	t_door	*d;
	int		new_x;
	int		new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return (1);
	if (game->map.grid[new_y][new_x] == '1')
		return (1);
	if (game->map.grid[new_y][new_x] == 'D')
	{
		d = get_door(game, new_x, new_y);
		if (d && d->frame < 4)
			return (1);
	}
	return (0);
}

int	can_move(t_game *game, double x, double y)
{
	double	dist;

	dist = 0.2;
	if (is_solid(game, x + dist, y + dist))
		return (0);
	if (is_solid(game, x - dist, y - dist))
		return (0);
	if (is_solid(game, x + dist, y - dist))
		return (0);
	if (is_solid(game, x - dist, y + dist))
		return (0);
	return (1);
}
