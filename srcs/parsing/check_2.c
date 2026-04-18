/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:28 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:28 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_clean_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\r' || line[i] == '\t')
		{
			printf("Error\nForbidden character detected\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!is_clean_line(array[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*formate_line(char *line, int width)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(line);
	new = malloc(sizeof(char) * (width + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	while (i < width)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(line);
	return (new);
}

int	formate_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = formate_line(game->map.grid[i], game->map.width);
		if (!game->map.grid[i])
		{
			printf("Error\nMalloc fail\n");
			return (0);
		}
		i++;
	}
	return (1);
}
