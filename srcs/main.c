
#include "../includes/cub3D.h"

// static int	load_texture(t_game *game, int i, char *path)
// {
// 	game->walls[i].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, path,
// 			&game->walls[i].width, &game->walls[i].height);
// 	if (!game->walls[i].img_ptr)
// 		return (0);
// 	game->walls[i].buffer = (int *)mlx_get_data_addr(game->walls[i].img_ptr,
// 			&game->walls[i].bpp, &game->walls[i].size_line, &game->walls[i].endian);
// 	if (!game->walls[i].buffer)
// 		return (0);
// 	game->walls[i].size_line /= 4;
// 	return (1);
// }

// static int	init_textures(t_game *game)
// {
// 	if (!load_texture(game, 0, game->texture.no))
// 		return (printf("Error\nFailed to load texture NO\n"), 0);
// 	if (!load_texture(game, 1, game->texture.so))
// 		return (printf("Error\nFailed to load texture SO\n"), 0);
// 	if (!load_texture(game, 2, game->texture.we))
// 		return (printf("Error\nFailed to load texture WE\n"), 0);
// 	if (!load_texture(game, 3, game->texture.ea))
// 		return (printf("Error\nFailed to load texture EA\n"), 0);
// 	return (1);
// }

static void	print_parsed_grid(t_game *game)
{
	int	i;

	printf("Parsed grid (%d x %d):\n", game->map.width, game->map.height);
	i = 0;
	while (i < game->map.height)
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
}

int	parsing(t_game *game, int ac, char **av)
{
	char    **array;
	int     map_start;

	init_game(game);
	if (ac != 2)
	{
		printf("Error\nbad arguments\n");
		return (1);
	}
	array = read_file_to_array(av[1]);
	if (!array)
		return (1);
	clean_array(array);
	map_start = find_start_map(array);
	if (map_start == -1)
	{
		free_grid(array);
		return (1);
	}
	if (!parsing_element(array, map_start, game))
	{
		free_grid(array);
		free_game(game);
		return (1);
	}
	if (!check_all_texture(&game->texture))
	{
		free_grid(array);
		free_game(game);
		return (1);
	}
	if (!parsing_map(array, map_start, game))
	{
		free_grid(array);
		free_game(game);
		return (1);
	}
	free_grid(array);
	if (!formate_map(game))
	{
		free_game(game);
		return (1);
	}
	if (!valid_map(game))
	{
		free_game(game);
		return (1);
	}
	print_parsed_grid(game);
	return (0);
}

// static void    mock_parsing(t_game *game)
// {
// 	game->map.width = 20;
// 	game->map.height = 20;
// 	game->map.grid = malloc(sizeof(char *) * 21);
	
// 	game->map.grid[0]  = strdup("11111111111111111111");
// 	game->map.grid[1]  = strdup("10000000000000000001");
// 	game->map.grid[2]  = strdup("10111110000011111101");
// 	game->map.grid[3]  = strdup("10100010000010000101");
// 	game->map.grid[4]  = strdup("10100010000010000101");
// 	game->map.grid[5]  = strdup("10000000000000000001");
// 	game->map.grid[6]  = strdup("10000000010000000001");
// 	game->map.grid[7]  = strdup("10110110000011011101");
// 	game->map.grid[8]  = strdup("10100010000010000101");
// 	game->map.grid[9]  = strdup("10000000000000000001");
// 	game->map.grid[10] = strdup("10000000110000000001");
// 	game->map.grid[11] = strdup("10110111111111011101");
// 	game->map.grid[12] = strdup("10000000000000000001");
// 	game->map.grid[13] = strdup("10111110000011111101");
// 	game->map.grid[14] = strdup("10100010011010000101");
// 	game->map.grid[15] = strdup("10100000011000000101");
// 	game->map.grid[16] = strdup("10111110000011111101");
// 	game->map.grid[17] = strdup("10000000000000000001");
// 	game->map.grid[18] = strdup("10000000000000000001");
// 	game->map.grid[19] = strdup("11111111111111111111");
// 	game->map.grid[20] = NULL;

// 	game->player.x = 2.5;
// 	game->player.y = 1.5;
// 	game->player.dir_x = 0;
// 	game->player.dir_y = -1;
// 	game->player.plane_x = 0.66;
// 	game->player.plane_y = 0;
// 	game->player.fov = 0.66;
// 	game->texture.floor = 0x444444; 
// 	game->texture.ceiling = 0x87CEEB;

// }

// void	init_textures(t_game *game)
// {
// 	game->walls[0].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_grey_north.xpm", &game->walls[0].width, &game->walls[0].height);
// 		if (!game->walls[0].img_ptr)
// 		{
// 			printf("Erreur : Impossible de charger la texture %d\n", 0);
// 			exit(1);
// 		}
// 	game->walls[1].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_blue_south.xpm", &game->walls[1].width, &game->walls[1].height);
// 		if (!game->walls[1].img_ptr)
// 		{
// 			printf("Erreur : Impossible de charger la texture %d\n", 1);
// 			exit(1);
// 		}
// 	game->walls[2].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_yellow_west.xpm", &game->walls[2].width, &game->walls[2].height);
// 		if (!game->walls[2].img_ptr)
// 		{
// 			printf("Erreur : Impossible de charger la texture %d\n", 2);
// 			exit(1);
// 		}
// 	game->walls[3].img_ptr = mlx_xpm_file_to_image(game->libx.mlx, "textures/Dungeon_brick_wall_purple_east.xpm", &game->walls[3].width, &game->walls[3].height);
// 	if (!game->walls[3].img_ptr)
// 		{
// 			printf("Erreur : Impossible de charger la texture %d\n", 3);
// 			exit(1);
// 		}
// 	int i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		game->walls[i].buffer = (int *)mlx_get_data_addr(game->walls[i].img_ptr, 
// 			&game->walls[i].bpp, &game->walls[i].size_line, &game->walls[i].endian);
// 		game->walls[i].size_line /= 4;
// 		i++;
// 	}
// }

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
	//mock_parsing(&game);
	if(parsing(&game, ac, av))
		return (0);
	if (!init_milx(&game.libx, &game))
		return (1);
	init_textures(&game);
	init_move_keys(&game);
	//move_player(&game);
	mlx_hook(game.libx.win, 2, 1L<<0, keys_move_press, &game);
	mlx_hook(game.libx.win, 3, 1L<<1, keys_move_release, &game);
	mlx_hook(game.libx.win, 17, 1L << 2,
		free_mlx_and_destroy, &game);
	//hook pour déplacement souris
	mlx_hook(game.libx.win, 6, 1L<<6, mouse_shift, &game);
	mlx_mouse_hide(game.libx.mlx, game.libx.win);
	mlx_loop_hook(game.libx.mlx, update_game, &game);
	mlx_loop(game.libx.mlx);
}
