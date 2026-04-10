#include "../../includes_bonus/cub3D_bonus.h"

static void	mock_init_textures(t_game *game)
{
	game->walls[0].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_grey_north.xpm", &game->walls[0].width, &game->walls[0].height);
		if (!game->walls[0].img_ptr)
		{
			printf("Erreur : Impossible de charger la texture %d\n", 0);
			exit(1);
		}
	game->walls[1].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_blue_south.xpm", &game->walls[1].width, &game->walls[1].height);
		if (!game->walls[1].img_ptr)
		{
			printf("Erreur : Impossible de charger la texture %d\n", 1);
			exit(1);
		}
	game->walls[2].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_yellow_west.xpm", &game->walls[2].width, &game->walls[2].height);
		if (!game->walls[2].img_ptr)
		{
			printf("Erreur : Impossible de charger la texture %d\n", 2);
			exit(1);
		}
	game->walls[3].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_purple_east.xpm", &game->walls[3].width, &game->walls[3].height);
	if (!game->walls[3].img_ptr)
		{
			printf("Erreur : Impossible de charger la texture %d\n", 3);
			exit(1);
		}
	int i;

	i = 0;
	while (i < 4)
	{
		game->walls[i].buffer = (int *)mlx_get_data_addr(game->walls[i].img_ptr, 
			&game->walls[i].bpp, &game->walls[i].size_line, &game->walls[i].endian);
		game->walls[i].size_line /= 4;
		i++;
	}
}

int	init_milx(t_milx *var, t_game *game)
{
	(void) game;
	var->mlx = mlx_init();
	if (!var->mlx)
		return (0);
	mlx_get_screen_size(var->mlx, &var->width_size, &var->height_size);
	var->width_size = var->width_size / 2;
	var->height_size = var->height_size / 2;
	var->win = mlx_new_window(var->mlx, var->width_size,
			var->height_size, "cub3D");
	if (!var->win)
		return (0);
	var->img = mlx_new_image(var->mlx, var->width_size, var->height_size);
	if (!var->img)
		return (0);
	var->buffer = (int *)mlx_get_data_addr(var->img, &var->bpp,
			&var->size_line, &var->endian);
	var->size_line /= 4;
	if (!var->buffer)
		return (0);
	return (1);
}

void	init_move_keys(t_game *game)
{
	game->move_keys.w = 0;
	game->move_keys.s = 0;
	game->move_keys.a = 0;
	game->move_keys.d = 0;
	game->move_keys.left = 0;
	game->move_keys.right = 0;
	game->pause_mouse = 1;
}

void	my_mlx_pixel_put(int y, int x, t_game *game, int color)
{
	int	pixel;

	pixel = (y * game->libx.size_line + x);
	game->libx.buffer[pixel] = color;
}

int	init_everything(t_game *game)
{
	if (!init_milx(&game->libx, game))
		return (1);
	//init_textures(game);
	mock_init_textures(game);
	if (!init_all_doors(game))
		return (1);
	init_move_keys(game);
	return (0);
}
