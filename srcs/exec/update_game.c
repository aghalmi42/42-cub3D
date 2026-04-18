/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:20 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:21 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	update_game(t_game *game)
{
	update_move_player(game);
	update_camera_shifting(game, -0.015);
	raycasting_to_3d(game);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win,
		game->libx.img, 0, 0);
	return (0);
}
