
#include "../includes_bonus/cub3D_bonus.h"

// int main(int ac, char **av)
// {
//     t_game  game;
//     char    **array;
//     int     map_start;

//     init_game(&game);
//     if (ac != 2)
//     {
//         printf("Error\nbad arguments\n");
//         return (1);
//     }
//     array = read_file_to_array(av[1]);
//     if (!array)
//         return (1);
//     clean_array(array);
//     map_start = find_start_map(array);
//     if (map_start == -1)
//     {
//         free_grid(array);
//         return (1);
//     }
//     if (!parsing_element(array, map_start, &game))
//     {
//         free_grid(array);
//         free_game(&game);
//         return (1);
//     }
//     if (!check_all_texture(&game.texture))
//     {
//         free_grid(array);
//         free_game(&game);
//         return (1);
//     }
//     if (!parsing_map(array, map_start, &game))
//     {
//         free_grid(array);
//         free_game(&game);
//         return (1);
//     }
//     free_grid(array);
//     if (!formate_map(&game))
//     {
//         free_game(&game);
//         return (1);
//     }
//     if (!valid_map(&game))
//     {
//         free_game(&game);
//         return (1);
//     }
//     return (0);
// }

static void init_door_instances(t_game *game)
{
	int x;
	int y;
	int d_idx;

	game->map.door_count = 0;
	y = -1;
	while (game->map.grid[++y])
	{
		x = -1;
		while (game->map.grid[y][++x])
			if (game->map.grid[y][x] == 'D')
				game->map.door_count++;
	}
	game->map.doors = malloc(sizeof(t_door) * game->map.door_count);
	d_idx = 0;
	y = -1;
	while (game->map.grid[++y])
	{
		x = -1;
		while (game->map.grid[y][++x])
		{
			if (game->map.grid[y][x] == 'D')
			{
				game->map.doors[d_idx].x = x;
				game->map.doors[d_idx].y = y;
				game->map.doors[d_idx].frame = 0;
				game->map.doors[d_idx].state = 0;
				game->map.doors[d_idx].timer = 0;
				d_idx++;
			}
		}
	}
}

void mock_parsing(t_game *game)
{
	game->map.width = 20;
	game->map.height = 20;
	game->map.grid = malloc(sizeof(char *) * 21);
	game->map.grid[0]  = strdup("11111111111111111111");
	game->map.grid[1]  = strdup("10000000000000000001");
	game->map.grid[2]  = strdup("10111D10000011D11101");
	game->map.grid[3]  = strdup("10100010000010000101");
	game->map.grid[4]  = strdup("10100010000010000101");
	game->map.grid[5]  = strdup("100000D00000D0000001");
	game->map.grid[6]  = strdup("10000000010000000001");
	game->map.grid[7]  = strdup("1011D110000011D11101");
	game->map.grid[8]  = strdup("10100010000010000101");
	game->map.grid[9]  = strdup("10000000000000000001");
	game->map.grid[10] = strdup("10000000110000000001");
	game->map.grid[11] = strdup("10110111111111D11101");
	game->map.grid[12] = strdup("10000000000000000001");
	game->map.grid[13] = strdup("1011D110000011111101");
	game->map.grid[14] = strdup("10100010011010000101");
	game->map.grid[15] = strdup("10100000011000000101");
	game->map.grid[16] = strdup("10111110000011111101");
	game->map.grid[17] = strdup("10000000000000000001");
	game->map.grid[18] = strdup("10000000000000000001");
	game->map.grid[19] = strdup("11111111111111111111");
	game->map.grid[20] = NULL;

	init_door_instances(game);

	// Joueur et textures
	game->player.x = 2.5;
	game->player.y = 1.5;
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->texture.floor = 0x444444; 
	game->texture.ceiling = 0x87CEEB;
}

int	free_mlx_and_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->walls[i].img_ptr)
			mlx_destroy_image(game->libx.mlx, game->walls[i].img_ptr);
		i++;
	}
	if (game->libx.img)
		mlx_destroy_image(game->libx.mlx, game->libx.img);
	if (game->libx.win)
	{
		mlx_destroy_window(game->libx.mlx, game->libx.win);
	}
		
	if (game->libx.mlx)
	{
		mlx_destroy_display(game->libx.mlx);
		free(game->libx.mlx);
	}
	exit (0);
}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_game game;

	if (init_everything(&game))
		return (1);
	mock_parsing(&game);
	mlx_hook(game.libx.win, 2, 1L<<0, keys_move_press, &game);
	mlx_hook(game.libx.win, 3, 1L<<1, keys_move_release, &game);
	mlx_hook(game.libx.win, 17, 1L << 2,
		free_mlx_and_destroy, &game);
	mlx_hook(game.libx.win, 6, 1L<<6, mouse_shift, &game);
	mlx_mouse_hide(game.libx.mlx, game.libx.win);
	mlx_loop_hook(game.libx.mlx, update_game, &game);
	mlx_loop(game.libx.mlx);
}
