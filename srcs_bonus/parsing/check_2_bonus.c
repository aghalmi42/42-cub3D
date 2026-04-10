
#include "../../includes_bonus/cub3D_bonus.h"

void	clean_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\r')
			line[i] = ' ';
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

void	clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		clean_line(array[i]);
		i++;
	}
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
