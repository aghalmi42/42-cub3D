
#include "../includes/cub3D.h"

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

void	free_game(t_game *game)
{
	free_texture(&game->texture);
	free_grid(game->map.grid);
}
