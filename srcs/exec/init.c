#include "../../includes/cub3D.h"

int init_milx(t_milx *var, t_game *game)
{
	(void) game;
	var->mlx = mlx_init();
	if (!var->mlx)
		return (0);
	mlx_get_screen_size(var->mlx, &var->width_size, &var->height_size);
	var->width_size = var->width_size * 2 / 3;
	var->height_size = var->height_size * 3 / 4;
	// var->width_size = 200;
	// var->height_size = 200;
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
}

void	my_mlx_pixel_put(int y, int x, t_game *game, int color)
{
	int	pixel;

	pixel = (y * game->libx.size_line + x);
	game->libx.buffer[pixel] = color;
}