
#include "../includes/cub3D.h"

void    init_game(t_game *game)
{
    game->texture.no = NULL;
    game->texture.so = NULL;
    game->texture.we = NULL;
    game->texture.ea = NULL;
    game->texture.floor = -1;
    game->texture.ceiling = -1;
    game->map.grid = NULL;
    game->map.width = 0;
    game->map.height = 0;
    game->player.x = 0;
    game->player.y = 0;
    game->player.dir_x = 0;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0;
    game->map.door_count = 0;
}

char *parsing_texture(char *line)
{
    int i;

    i = 0;
    while(line[i] && line[i] != ' ')
        i++;
    while(line[i] && line[i] == ' ')
        i++;
    if (!line[i])
        return (NULL);
    return (ft_strdup(line + i));
}

int parsing_color(char *line)
{
    int i;
    int r;
    int g;
    int b;
    char **rgb;

    i = 0;
    while(line[i] && line[i] != ' ')
        i++;
    while(line[i] && line[i] == ' ')
        i++;
    if (!line[i])
        return (-1);
    rgb = ft_split(line + i, ',');
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        free_grid(rgb);
        return (-1);
    }
    free_grid(rgb);
    return ((r << 16) | (g << 8) | b);
}

int	parsing_texture_id(char *line, t_game *game)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		game->texture.no = parsing_texture(line);
		return (game->texture.no != NULL);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		game->texture.so = parsing_texture(line);
		return (game->texture.so != NULL);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		game->texture.we = parsing_texture(line);
		return (game->texture.we != NULL);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		game->texture.ea = parsing_texture(line);
		return (game->texture.ea != NULL);
	}
	return (-1);
}

int	parsing_color_id(char *line, t_game *game)
{
	if (line[0] == 'F')
	{
		game->texture.floor = parsing_color(line);
		return (game->texture.floor != -1);
	}
	else if (line[0] == 'C')
	{
		game->texture.ceiling = parsing_color(line);
		return (game->texture.ceiling != -1);
	}
	return (-1);
}
