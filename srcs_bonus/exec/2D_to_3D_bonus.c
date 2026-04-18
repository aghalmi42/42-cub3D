/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_to_3D_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:53:58 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:53:59 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

void	raycasting_to_3d(t_game *game)
{
	int			x;
	double		camera_x;
	t_ray		ray;
	t_line_vert	line;

	x = 0;
	while (x < game->libx.width_size)
	{
		camera_x = 2 * x / (double)game->libx.width_size - 1;
		ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
		init_ray_dda(game, 0, &ray, 0);
		line.line_height = (int)(game->libx.height_size / ray.real_dist);
		line.start_line = -line.line_height / 2 + game->libx.height_size / 2;
		if (line.start_line < 0)
			line.start_line = 0;
		line.end_line = line.line_height / 2 + game->libx.height_size / 2;
		if (line.end_line >= game->libx.height_size)
			line.end_line = game->libx.height_size - 1;
		display_vertical_line_with_textures(game, x, &ray, line);
		x++;
	}
}
