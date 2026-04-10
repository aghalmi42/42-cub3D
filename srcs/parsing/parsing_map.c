
#include "../includes/cub3D.h"

int     is_player(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void    find_player(char *line, int y, t_game *game)
{
    int x;

    x = 0;
    while (line[x])
    {
        if (is_player(line[x]))
        {
            game->player.x = x;
            game->player.y = y;
            set_dir_player(line[x], game);
        }
        x++;
    }
}

int fill_grid(char **array, int map_start, t_game * game)
{
    int i;

    i = 0;
    while(i < game->map.height)
    {
        game->map.grid[i] = ft_strdup(array[map_start + i]);
        if (!game->map.grid[i])
        {
            printf("Error\nMalloc fail");
            return (0);
        }
        find_player(game->map.grid[i], i, game);
        i++;
    }
    game->map.grid[i] = NULL;
    return (1);
}

int parsing_map(char **array, int map_start, t_game *game)
{
    map_dimension(array, map_start, game);
    if (!malloc_grid(game))
        return (0);
    if (!fill_grid(array, map_start, game))
        return (0);
    return (1);
}
