
#include "../includes/cub3D.h"

int find_start_map(char **array)
{
    int i;
    int j;

    i = 0;
    while(array[i])
    {
        j = 0;
        while (array[i][j] == ' ' || array[i][j] == '\t')
            j++;
        if (array[i][j] == '1' || array[i][j] == '0' || array[i][j] == ' ')
            return (i);
        if ((array[i][j] == 'N' || array[i][j] == 'S'
            || array[i][j] == 'E' || array[i][j] == 'W')
            && (array[i][j + 1] == '0' || array[i][j + 1] == '1'
            || array[i][j + 1] == ' ' || array[i][j + 1] == '\0'))
            return (i);
        i++;
    }
    return (-1);
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
	printf("north : %s\n south : %s \n we : %s\n east : %s\n floor : %d ceiling : %d\n", game->texture.no,game->texture.so, game->texture.we, game->texture.ea, game->texture.floor, game->texture.ceiling);
    if (!game->texture.no || !game->texture.so
        || !game->texture.we || !game->texture.ea)
        return (0);
    if (game->texture.floor == -1 || game->texture.ceiling == -1)
        return (0);
    return (1);
}
