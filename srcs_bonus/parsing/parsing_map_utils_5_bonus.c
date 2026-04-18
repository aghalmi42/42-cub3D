/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_5_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:54 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:54 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

void	map_dimension(char **array, int map_start, t_game *game)
{
	int	i;
	int	len;

	i = map_start;
	game->map.height = 0;
	game->map.width = 0;
	while (array[i])
	{
		len = ft_strlen(array[i]);
		game->map.height++;
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
}

int	malloc_grid(t_game *game)
{
	int	i;

	i = 0;
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
	{
		printf("Error\nMalloc fail");
		return (0);
	}
	while (i <= game->map.height)
	{
		game->map.grid[i] = NULL;
		i++;
	}
	return (1);
}

void	set_dir_ns(char c, t_game *game)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

void	set_dir_ew(char c, t_game *game)
{
	if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	set_dir_player(char c, t_game *game)
{
	if (c == 'N' || c == 'S')
		set_dir_ns(c, game);
	else
		set_dir_ew(c, game);
}
