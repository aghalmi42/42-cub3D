/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:55 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:56 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*parsing_texture(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (NULL);
	return (ft_strdup(line + i));
}

int	pass_spaces_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int	parsing_texture_id(char *line, t_game *game)
{
	int	i;

	i = pass_spaces_in_line(line);
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		if (game->texture.no)
		{
			printf("Error\nDouble definition of NO texture\n");
			return (0);
		}
		game->texture.no = parsing_texture(line, i + 2);
		return (game->texture.no != NULL);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		if (game->texture.so)
		{
			printf("Error\nDouble definition of SO texture\n");
			return (0);
		}
		game->texture.so = parsing_texture(line, i + 2);
		return (game->texture.so != NULL);
	}
	return (parsing_texture_id_two(line, game, i));
}

int	parsing_texture_id_two(char *line, t_game *game, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		if (game->texture.we)
		{
			printf("Error\nDouble definition of WE texture\n");
			return (0);
		}
		game->texture.we = parsing_texture(line, i + 2);
		return (game->texture.we != NULL);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
	{
		if (game->texture.ea)
		{
			printf("Error\nDouble definition of EA texture\n");
			return (0);
		}
		game->texture.ea = parsing_texture(line, i + 2);
		return (game->texture.ea != NULL);
	}
	return (-1);
}
