/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:54:29 by aghalmi           #+#    #+#             */
/*   Updated: 2026/05/01 12:46:57 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

void init_dooors(t_game *game)
{
	int		side;
	int		frame;

	side = 0;
	while (side < 4)
	{
		frame = 0;
		while (frame < 5)
		{
			game->doors[side][frame].img_ptr = NULL;
			frame++;
		}
		side++;
	}
}

int	init_all_doors(t_game *game)
{
	int		side;
	int		frame;
	char	*prefixes[4];

	side = 0;
	init_prefixes(prefixes);
	init_dooors(game);
	while (side < 4)
	{
		frame = 0;
		while (frame < 5)
		{
			if (!init_one_door_frame(game, side, frame, prefixes))
				return (0);
			frame++;
		}
		side++;
	}
	return (1);
}

int	init_one_door_frame(t_game *game, int side, int frame, char *prefixes[4])
{
	char	*path;

	path = init_path_one_door_frame(prefixes, frame, side);
	if (!path)
		return (0);
	game->doors[side][frame].img_ptr = mlx_xpm_file_to_image(game->libx.mlx,
			path, &game->doors[side][frame].width,
			&game->doors[side][frame].height);
	if (!game->doors[side][frame].img_ptr)
		return (printf("Error\n Impossible to load this texture : %s\n", path),
			free(path), 0);
	game->doors[side][frame].buffer = (int *)mlx_get_data_addr(
			game->doors[side][frame].img_ptr, &game->doors[side][frame].bpp,
			&game->doors[side][frame].size_line,
			&game->doors[side][frame].endian);
	free(path);
	return (1);
}

char	*init_path_one_door_frame(char *prefixes[4], int frame, int side)
{
	char	*path;
	char	*tmp;
	char	*nb;

	nb = ft_itoa(frame + 1);
	if (!nb)
		return (NULL);
	tmp = ft_strjoin("textures/", prefixes[side]);
	if (!tmp)
		return (free(nb), NULL);
	path = ft_strjoin(tmp, "_door_");
	if (!path)
		return (free(nb), free(tmp), NULL);
	free(tmp);
	tmp = ft_strjoin(path, nb);
	if (!tmp)
		return (free(nb), free(path), NULL);
	free(path);
	path = ft_strjoin(tmp, ".xpm");
	if (!path)
		return (free(tmp), free(nb), NULL);
	free(tmp);
	free(nb);
	return (path);
}

void	init_prefixes(char *prefixes[4])
{
	prefixes[0] = "north";
	prefixes[1] = "south";
	prefixes[2] = "west";
	prefixes[3] = "east";
}
