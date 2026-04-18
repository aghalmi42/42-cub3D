/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:53:40 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:53:40 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (parsing(&game, ac, av))
		return (0);
	if (init_everything(&game))
		return (1);
	mlx_hook(game.libx.win, 2, 1L << 0, keys_move_press, &game);
	mlx_hook(game.libx.win, 3, 1L << 1, keys_move_release, &game);
	mlx_hook(game.libx.win, 17, 1L << 2,
		free_mlx_and_destroy, &game);
	mlx_loop_hook(game.libx.mlx, update_game, &game);
	mlx_loop(game.libx.mlx);
}
