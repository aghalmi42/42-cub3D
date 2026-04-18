/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:32 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:33 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_commas(char *line, int i)
{
	int	cpt;

	cpt = 0;
	while (line[i])
	{
		if (line[i] == ',')
			cpt++;
		i++;
	}
	if (cpt != 2)
		return (0);
	return (1);
}

int	check_numeric_rgb(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j] && rgb[i][j] == ' ')
			j++;
		if (!rgb[i][j])
			return (0);
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != ' ')
				return (0);
			j++;
		}
		while (rgb[i][j] && (rgb[i][j] == ' '))
			j++;
		if (rgb[i][j])
			return (0);
		i++;
	}
	return (1);
}
