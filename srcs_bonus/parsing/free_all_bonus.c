
#include "../../includes_bonus/cub3D_bonus.h"

void	free_texture(t_texture *texture)
{
	if (texture->no)
		free(texture->no);
	if (texture->so)
		free(texture->so);
	if (texture->we)
		free(texture->we);
	if (texture->ea)
		free(texture->ea);
}

void	free_door(t_map *map)
{
	if (map->doors)
		free(map->doors);
}

void	free_game(t_game *game)
{
	free_texture(&game->texture);
	free_grid(game->map.grid);
	free_door(&game->map);
}
