/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:20 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:21 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3D_bonus.h"

void	init_game(t_game *game)
{
	game->texture.no = NULL;
	game->texture.so = NULL;
	game->texture.we = NULL;
	game->texture.ea = NULL;
	game->texture.floor = -1;
	game->texture.ceiling = -1;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->map.door_count = 0;
}
