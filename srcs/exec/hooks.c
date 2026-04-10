#include "../../includes/cub3D.h"

int keys_move_press(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->move_keys.left = 1;
	if (keycode == KEY_RIGHT)
		game->move_keys.right = 1;
	if (keycode == KEY_Z)
		game->move_keys.w = 1;
	if (keycode == KEY_S)
		game->move_keys.s = 1;
	if (keycode == KEY_Q)
		game->move_keys.a = 1;
	if (keycode == KEY_D)
		game->move_keys.d = 1;
	if (keycode == KEY_ESC)
	{
		free_grid(game->map.grid);
		free_mlx_and_destroy(game);
		exit(0);
	}
	return (0);
}

int keys_move_release(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->move_keys.left = 0;
	if (keycode == KEY_RIGHT)
		game->move_keys.right = 0;
	if (keycode == KEY_Z)
		game->move_keys.w = 0;
	if (keycode == KEY_S)
		game->move_keys.s = 0;
	if (keycode == KEY_Q)
		game->move_keys.a = 0;
	if (keycode == KEY_D)
		game->move_keys.d = 0;
	return (0);
}

int	mouse_shift(int x, int y, t_game *game)
{
	int		center;
	double	rotate_speed;

	(void)y;
	center = game->libx.width_size / 2;
	if (x == center)
		return (0);
	rotate_speed = (double)(x - center) * 0.002;
	game->move_keys.left = 1;
	update_camera_shifting(game, rotate_speed);
	game->move_keys.left = 0;
	mlx_put_image_to_window(game->libx.mlx, game->libx.win,
	game->libx.img, 0, 0);
	mlx_mouse_move(game->libx.mlx, game->libx.win, center, game->libx.height_size / 2);
	return (0);
}
