/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:07 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:07 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

int	check_extension_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

int	check_file_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_texture(char *path)
{
	if (!check_extension_xpm(path))
	{
		printf("Error\nTexture is .xpm: %s\n", path);
		return (0);
	}
	if (!check_file_exist(path))
	{
		printf("Error\nTexture not found: %s\n", path);
		return (0);
	}
	return (1);
}

int	check_all_texture(t_texture *texture)
{
	if (!check_texture(texture->no))
		return (0);
	if (!check_texture(texture->so))
		return (0);
	if (!check_texture(texture->we))
		return (0);
	if (!check_texture(texture->ea))
		return (0);
	return (1);
}
