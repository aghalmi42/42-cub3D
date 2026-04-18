/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:25 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:26 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3D_bonus.h"

int	parsing(t_game *game, int ac, char **av)
{
	char	**array;
	int		map_start;

	array = NULL;
	if (ac != 2)
		return (printf("Error\nWrong numbers of arguments\n"), 1);
	if (!set_parsing_elements(game, &array, &map_start, av))
		return (1);
	if (!parsing_first_part(game, array, map_start))
		return (free_grid(array), free_game(game), 1);
	free_grid(array);
	if (!formate_map(game))
		return (free_game(game), 1);
	if (!valid_map(game))
		return (free_game(game), 1);
	if (!parsing_door(game))
		return (free_game(game), 1);
	return (0);
}

int	set_parsing_elements(t_game *game, char ***array, int *map_start, char **av)
{
	init_game(game);
	*array = read_file_to_array(av[1]);
	if (!*array)
		return (0);
	if (!is_clean_array(*array))
		return (free_grid(*array), 0);
	*map_start = find_start_map(*array);
	if (*map_start == -1)
	{
		free_grid(*array);
		return (0);
	}
	return (1);
}

int	parsing_first_part(t_game *game, char **array, int map_start)
{
	if (!parsing_element(array, map_start, game))
		return (0);
	if (!check_all_texture(&game->texture))
		return (0);
	if (!parsing_map(array, map_start, game))
		return (0);
	return (1);
}
