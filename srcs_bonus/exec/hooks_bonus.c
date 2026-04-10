#include "../../includes_bonus/cub3D_bonus.h"

int	keys_move_press(int keycode, t_game *game)
{
	if (keycode == KEY_P)
		pause_mouse(game);
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
	if (keycode == KEY_E)
		interact_with_door(game);
	return (0);
}

void	pause_mouse(t_game *game)
{
	game->pause_mouse = -game->pause_mouse;
	if (game->pause_mouse == 1)
		mlx_mouse_hide(game->libx.mlx, game->libx.win);
	else
		mlx_mouse_show(game->libx.mlx, game->libx.win);
}

int	keys_move_release(int keycode, t_game *game)
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
	if (game->pause_mouse == -1)
		return (0);
	center = game->libx.width_size / 2;
	if (x == center)
		return (0);
	rotate_speed = (double)(x - center)*0.002;
	game->move_keys.left = 1;
	update_camera_shifting(game, rotate_speed);
	game->move_keys.left = 0;
	mlx_put_image_to_window(game->libx.mlx, game->libx.win,
		game->libx.img, 0, 0);
	mlx_mouse_move(game->libx.mlx, game->libx.win, center,
		game->libx.height_size / 2);
	return (0);
}

void	interact_with_door(t_game *game)
{
	int			next_x;
	int			next_y;
	t_door		*door;
	double		reach;

	reach = 0.8;
	next_x = (int)(game->player.x + game->player.dir_x * reach);
	next_y = (int)(game->player.y + game->player.dir_y * reach);
	if (next_x < 0 || next_x >= game->map.width
		|| next_y < 0 || next_y >= game->map.height)
		return ;
	if (game->map.grid[next_y][next_x] == 'D')
	{
		door = get_door(game, next_x, next_y);
		if (!door)
			return ;
		if (door->state == 0 || door->state == 3)
			door->state = 1;
		else if (door->state == 2 || door->state == 1)
			door->state = 3;
	}
}
