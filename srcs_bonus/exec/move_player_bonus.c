/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:54:45 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:54:46 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

// void	move_player(t_game *game)
// {
// 	double	x;
// 	double	y;
// 	int		color;

// 	y = 0;
// 	while (y != game->map.height)
// 	{
// 		x = 0;
// 		while (x != game->map.width)
// 		{
// 			if (game->map.grid[(int)y][(int)x] == '1')
// 				color = RED;
// 			else if (game->map.grid[(int)y][(int)x] == '0')
// 				color = ORANGE;
// 			display_rect(game, x * TILE_SIZE,
// 				y * TILE_SIZE, TILE_SIZE - 1, color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	display_rect(game, game->player.x * TILE_SIZE - 4,
// 		game->player.y * TILE_SIZE - 4, 8, BLUE);
// 	dda(game, 0);
// 	mlx_put_image_to_window(game->libx.mlx, game->libx.win,
// 		game->libx.img, 0, 0);
// }

void	display_player_direction(t_game *game)
{
	t_line_calc	line;

	line.player_x = game->player.x * TILE_SIZE;
	line.player_y = game->player.y * TILE_SIZE;
	line.end_dir_x = line.player_x + (game->player.dir_x * 20);
	line.end_dir_y = line.player_y + (game->player.dir_y * 20);
	line.dx = line.end_dir_x - line.player_x;
	line.dy = line.end_dir_y - line.player_y;
	if (fabs(line.dx) > fabs(line.dy))
		line.steps = fabs(line.dx);
	else
		line.steps = fabs(line.dy);
	line.x_incrase = line.dx / (double)line.steps;
	line.y_incrase = line.dy / (double)line.steps;
	display_line(game, &line, WHITE);
}
