#include "../../includes/cub3D.h"

void	display_minimap(t_game *game)
{
	t_minimap	mmap;

	mmap.minimap_tile = MINIMAP_SIZE / (MINIMAP_RANGE * 2);
	mmap.y = 0;
	while (mmap.y < MINIMAP_SIZE)
	{
		mmap.x = 0;
		while (mmap.x < MINIMAP_SIZE)
		{
			mmap.map_x = game->player.x + (double)(mmap.x - MINIMAP_SIZE / 2) / mmap.minimap_tile;
			mmap.map_y = game->player.y + (double)(mmap.y - MINIMAP_SIZE / 2) / mmap.minimap_tile;
			
			if (mmap.map_y < 0 || mmap.map_y >= game->map.height || 
				mmap.map_x < 0 || mmap.map_x >= game->map.width)
				mmap.color = BLACK;
			else
			{
				if (game->map.grid[(int)mmap.map_y][(int)mmap.map_x] == '1')
					mmap.color = RED;
				else
					mmap.color = ORANGE;
			}
			my_mlx_pixel_put(mmap.y, mmap.x, game, mmap.color);
			mmap.x++;
		}
		mmap.y++;
	}
	display_multiple_border_minimap(mmap, game);
	display_player_minimap(game);
	dda(game, 1);
	mlx_put_image_to_window(game->libx.mlx, game->libx.win,
	game->libx.img, 0, 0);
}


void	display_border_minimaap(t_minimap mmap, t_game *game, int i)
{
	int	start;

	start = i;
	mmap.color = BLUE;
	while (start < mmap.size_border)
	{
		my_mlx_pixel_put(start, i, game, mmap.color);
		my_mlx_pixel_put(start, mmap.size_border - 1, game,  mmap.color);
		my_mlx_pixel_put(i, start, game, mmap.color);
		my_mlx_pixel_put(mmap.size_border - 1, start, game,  mmap.color);
		start++;
	}
}

void	display_multiple_border_minimap(t_minimap mmap, t_game *game)
{
	int	i;

	i = 0;
	mmap.size_border = MINIMAP_SIZE;
	while (i < 5)
	{
		display_border_minimaap(mmap, game, i);
		mmap.size_border--;
		i++;
	}
}

void	display_player_minimap(t_game *game)
{
	int	center;
	int x;
	int	y;
	int	color;

	color = 0x00FF00;
	center = MINIMAP_SIZE / 2;
	y = center - 2;
	while (y < center + 2)
	{
		x = center - 2;
		while (x < center + 2)
		{
			my_mlx_pixel_put(y, x, game, color);
			x++;
		}
		y++;
	}
}