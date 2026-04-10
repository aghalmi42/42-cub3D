
#include "../../includes_bonus/cub3D_bonus.h"

int	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (grid[y][x] == '1' || grid[y][x] == 'X' || grid[y][x] == 'D')
		return (1);
	grid[y][x] = 'X';
    if (!flood_fill(grid, x + 1, y, map))
        return (0);
    if (!flood_fill(grid, x - 1, y, map))
        return (0);
    if (!flood_fill(grid, x, y + 1, map))
        return (0);
    if (!flood_fill(grid, x, y - 1, map))
        return (0);
    return (1);
}

int	check_flood_result(t_map *map, char **grid)
{
	(void)map;
	(void)grid;
	return (1);
}

int	valid_track(t_game *game)
{
	char	**grid_copy;
	int		result;

	grid_copy = copy_grid(&game->map);
	if (!grid_copy)
	{
		printf("Error\nFail memory allocation\n");
		return (0);
	}
	if (!flood_fill(grid_copy, game->player.x, game->player.y, &game->map))
        result = 0;
    else
        result = check_flood_result(&game->map, grid_copy);
    free_grid(grid_copy);
	return (result);
}
