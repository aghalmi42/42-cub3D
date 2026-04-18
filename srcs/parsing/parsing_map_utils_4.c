/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:53:04 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:53:04 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	find_start_map(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] && array[i][j] == ' ')
			j++;
		if (array[i][j])
		{
			if (check_start_map(array[i][j], array[i][j + 1]))
				return (i);
		}
		i++;
	}
	return (-1);
}

int	check_start_map(char c, char d)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (d && d != 'O' && d != 'A' && d != 'E')
			return (1);
		else if (!c)
			return (1);
	}
	return (0);
}

int	parsing_line(char *line, t_game *game)
{
	int	result;

	if (!line)
		return (1);
	result = parsing_texture_id(line, game);
	if (result == -1)
		result = parsing_color_id(line, game);
	if (result == -1)
	{
		printf("Error\nInvalid line format : \"%s\"\n", line);
		return (0);
	}
	if (result == 0)
		return (0);
	return (1);
}

int	parsing_element(char **array, int map_start, t_game *game)
{
	int	i;

	i = 0;
	while (i < map_start)
	{
		if (array[i][0] != '\0')
			if (!parsing_line(array[i], game))
				return (0);
		i++;
	}
	if (!check_all_element(game))
	{
		printf("Error\nMissing element or map isn't at the end of the file\n");
		return (0);
	}
	return (1);
}

int	check_all_element(t_game *game)
{
	if (!game->texture.no || !game->texture.so
		|| !game->texture.we || !game->texture.ea)
		return (0);
	if (game->texture.floor == -1 || game->texture.ceiling == -1)
		return (0);
	return (1);
}
