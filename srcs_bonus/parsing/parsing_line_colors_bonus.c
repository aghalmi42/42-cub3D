/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_colors_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:34 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:35 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3D_bonus.h"

int	parsing_color(char *line, int i)
{
	int		color;
	char	**rgb;

	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (-1);
	if (!check_commas(line, i))
	{
		printf("Error\nWrong number of commas for a certain colour\n");
		return (-1);
	}
	rgb = rgb_split_to_return(line, i);
	if (!rgb)
		return (-1);
	color = color_to_return(rgb);
	free_grid(rgb);
	return (color);
}

char	**rgb_split_to_return(char *line, int i)
{
	char	**rgb;

	rgb = ft_split(line + i, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_grid(rgb);
		printf("Error\nSplit fail for color\n");
		return (NULL);
	}
	if (!check_numeric_rgb(rgb))
	{
		free_grid(rgb);
		printf("Error\nNon numeric characters presents in a colour\n");
		return (NULL);
	}
	return (rgb);
}

int	color_to_return(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error\nR G or B too high or too low for a certain color\n");
		return (-1);
	}
	return ((r << 16) | (g << 8) | b);
}

int	parsing_color_id(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'F')
	{
		if (game->texture.floor != -1)
		{
			printf("Error\nDouble definition of Floor Colour\n");
			return (0);
		}
		game->texture.floor = parsing_color(line, i + 1);
		return (game->texture.floor != -1);
	}
	return (parsing_color_id_two(line, game, i));
}

int	parsing_color_id_two(char *line, t_game *game, int i)
{
	if (line[i] == 'C')
	{
		if (game->texture.ceiling != -1)
		{
			printf("Error\nDouble definition of Ceiling Colour\n");
			return (0);
		}
		game->texture.ceiling = parsing_color(line, i + 1);
		return (game->texture.ceiling != -1);
	}
	return (-1);
}
