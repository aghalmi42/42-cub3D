/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:51:58 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:51:59 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
