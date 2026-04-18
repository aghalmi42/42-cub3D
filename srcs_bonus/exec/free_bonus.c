/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:54:18 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:54:19 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3D_bonus.h"

int	free_mlx_and_destroy(t_game *game)
{
	int	i;

	i = 0;
	free_grid(game->map.grid);
	while (i < 4)
	{
		if (game->walls[i].img_ptr)
			mlx_destroy_image(game->libx.mlx, game->walls[i].img_ptr);
		i++;
	}
	free_door_ptr(game);
	if (game->libx.img)
		mlx_destroy_image(game->libx.mlx, game->libx.img);
	if (game->libx.win)
	{
		mlx_destroy_window(game->libx.mlx, game->libx.win);
	}
	if (game->libx.mlx)
	{
		mlx_destroy_display(game->libx.mlx);
		free(game->libx.mlx);
	}
	free_texture_ptr(game);
	exit (0);
}

void	free_texture_ptr(t_game *game)
{
	free(game->texture.so);
	free(game->texture.no);
	free(game->texture.ea);
	free(game->texture.we);
}

void	free_door_ptr(t_game *game)
{
	int		side;
	int		frame;

	side = 0;
	while (side < 4)
	{
		frame = 0;
		while (frame < 5)
		{
			if (game->doors[side][frame].img_ptr)
				mlx_destroy_image(game->libx.mlx,
					game->doors[side][frame].img_ptr);
			frame++;
		}
		side++;
	}
	free(game->map.doors);
}
