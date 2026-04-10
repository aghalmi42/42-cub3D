
#include "../../includes_bonus/cub3D_bonus.h"

int find_start_map(char **array)
{
    int i;

    i = 0;
    while(array[i])
    {
        if (array[i][0] == '1' || array[i][0] == '0'
            || array[i][0] == 'N' || array[i][0] == 'S'
            || array[i][0] == 'E' || array[i][0] == 'W'
            || array[i][0] == ' ')
            return (i);
        i++;
    }
    return(-1);
}

int	parsing_line(char *line, t_game *game)
{
	int	result;

	result = parsing_texture_id(line, game);
	if (result == -1)
		result = parsing_color_id(line, game);
	if (result == -1)
	{
		printf("Error\nUnknown id\n");
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
		printf("Error\nMissing element\n");
		return (0);
	}
	return (1);
}

int check_all_element(t_game *game)
{
    if (!game->texture.no || !game->texture.so
        || !game->texture.we || !game->texture.ea)
        return (0);
    if (game->texture.floor == -1 || game->texture.ceiling == -1)
        return (0);
    return (1);
}
