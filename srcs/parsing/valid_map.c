/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:53:29 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:53:29 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_valid_element(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
				&& c != 'W' && c != ' ')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	count_element(t_map *map, int *player_count)
{
	int		x;
	int		y;
	char	c;

	*player_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				(*player_count)++;
			x++;
		}
		y++;
	}
}

int	valid_map(t_game *game)
{
	int	player_count;

	if (!check_valid_element(&game->map))
	{
		printf("Error\nMap contain invalid character\n");
		return (0);
	}
	if (!valid_track(game))
	{
		printf("Error\nMap is not closed\n");
		return (0);
	}
	count_element(&game->map, &player_count);
	if (player_count != 1)
	{
		printf("Error\nPlayer not present in the map\n");
		return (0);
	}
	return (1);
}
