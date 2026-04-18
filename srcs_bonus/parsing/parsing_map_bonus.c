/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:41 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:41 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	find_player(char *line, int y, t_game *game)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (is_player(line[x]))
		{
			game->player.x = x + 0.5;
			game->player.y = y + 0.5;
			set_dir_player(line[x], game);
		}
		x++;
	}
}

int	fill_grid(char **array, int map_start, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = ft_strdup(array[map_start + i]);
		if (!game->map.grid[i])
		{
			printf("Error\nMalloc fail");
			return (0);
		}
		find_player(game->map.grid[i], i, game);
		i++;
	}
	game->map.grid[i] = NULL;
	return (1);
}

int	check_empty_lines_in_map(char **array, int map_start)
{
	int	i;
	int	empty;
	int	j;

	i = map_start;
	empty = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] && array[i][j] == ' ')
			j++;
		if (array[i][j] == '\0')
			empty = 1;
		else if (empty)
		{
			printf("Error\nMap splitted with empty lines\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing_map(char **array, int map_start, t_game *game)
{
	map_dimension(array, map_start, game);
	if (!check_empty_lines_in_map(array, map_start))
		return (0);
	if (!malloc_grid(game))
		return (0);
	if (!fill_grid(array, map_start, game))
		return (0);
	return (1);
}
