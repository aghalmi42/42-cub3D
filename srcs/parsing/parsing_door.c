
#include "../includes/cub3D.h"

// void	count_door(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	game->map.door_count = 0;
// 	y = 0;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < game->map.width)
//         {
// 			if (game->map.grid[y][x] == 'D')
// 				game->map.door_count++;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	malloc_door(t_game *game)
// {
// 	game->map.door_x = malloc(sizeof(int) * (game->map.door_count + 1));
// 	if (!game->map.door_x)
// 		return (0);
// 	game->map.door_y = malloc(sizeof(int) * (game->map.door_count + 1));
// 	if (!game->map.door_y)
// 	{
// 		free(game->map.door_x);
// 		return (0);
// 	}
// 	return (1);
// }

// void	fill_door(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	i;

// 	i = 0;
// 	y = 0;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < game->map.width)
// 		{
// 			if (game->map.grid[y][x] == 'D')
// 			{
// 				game->map.door_x[i] = x;
// 				game->map.door_y[i] = y;
// 				i++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	parsing_door(t_game *game)
// {
// 	count_door(game);
// 	if (game->map.door_count == 0)
// 		return (1);
// 	if (!malloc_door(game))
// 	{
// 		printf("Error\nMalloc fail for door\n");
// 		return (0);
// 	}
// 	fill_door(game);
// 	return (1);
// }
