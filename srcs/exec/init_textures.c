#include "../../includes/cub3D.h"

void	init_textures(t_game *game)
{
	game->walls[0].img_ptr = mlx_xpm_file_to_image(game->libx.mlx,
			game->texture.no, &game->walls[0].width, &game->walls[0].height);
	handle_error_init_textures(game->walls[0].img_ptr, game->texture.no);
	game->walls[1].img_ptr = mlx_xpm_file_to_image(game->libx.mlx,
			game->texture.so, &game->walls[1].width, &game->walls[1].height);
	handle_error_init_textures(game->walls[1].img_ptr, game->texture.so);
	game->walls[2].img_ptr = mlx_xpm_file_to_image(game->libx.mlx,
			game->texture.we, &game->walls[2].width, &game->walls[2].height);
	handle_error_init_textures(game->walls[1].img_ptr, game->texture.we);
	game->walls[3].img_ptr = mlx_xpm_file_to_image(game->libx.mlx,
			game->texture.ea, &game->walls[3].width, &game->walls[3].height);
	handle_error_init_textures(game->walls[1].img_ptr, game->texture.ea);
	send_textures_to_buffer(game);
}

void	send_textures_to_buffer(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->walls[i].buffer = (int *)mlx_get_data_addr(game->walls[i].img_ptr,
				&game->walls[i].bpp, &game->walls[i].size_line,
				&game->walls[i].endian);
		game->walls[i].size_line /= 4;
		i++;
	}
}

void	handle_error_init_textures(void	*img, char *name_texture)
{
	if (!img)
	{
		printf("Error\nImpossible to load this texture : %s\n", name_texture);
		exit(1);
	}
}
