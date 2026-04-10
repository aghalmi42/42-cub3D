
#include "../../includes_bonus/cub3D_bonus.h"

void	count_door(t_game *game)
{
	int	x;
	int	y;

	game->map.door_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'D')
				game->map.door_count++;
			x++;
		}
		y++;
	}
}

int	malloc_door(t_game *game)
{
	game->map.doors = malloc(sizeof(t_door) * game->map.door_count);
	if (!game->map.doors)
		return (0);
	return (1);
}

void	fill_door(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'D')
			{
				game->map.doors[i].x = x;
				game->map.doors[i].y = y;
				game->map.doors[i].frame = 0;
				game->map.doors[i].state = 0;
				game->map.doors[i].timer = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	parsing_door(t_game *game)
{
	count_door(game);
	if (game->map.door_count == 0)
		return (1);
	if (!malloc_door(game))
	{
		printf("Error\nMalloc fail for door\n");
		return (0);
	}
	fill_door(game);
	return (1);
}
