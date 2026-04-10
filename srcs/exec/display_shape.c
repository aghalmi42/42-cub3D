#include "../../includes/cub3D.h"

void display_rect(t_game *game, int x, int y, int size, int color)
{
	int i;
	int pixel;

	i = y;
	while (i < y + size)
	{
		int j = x;
		while (j < x + size)
		{
			pixel = (i * game->libx.size_line + j);
			game->libx.buffer[pixel] = color;
			j++;
		}
		i++;
	}
}

void	display_line(t_game *game, t_line_calc *line, int color)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = line->player_x;
	y = line->player_y;
	while (i < line->steps)
	{
		if (game->map.grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
			break ;
		if ((int)x >= 0 && (int)x < game->map.width * TILE_SIZE
			&& (int)y >= 0 && (int)y < game->map.height * TILE_SIZE)
			my_mlx_pixel_put(y, x, game, color);
		x += line->x_incrase;
		y += line->y_incrase;
		i++;
	}
}

void	display_line_minimap(t_game *game, t_line_calc *line, int color)
{
	int		i;
	double	x;
	double	y;
	double	max_radius;
	double	center;

	center = MINIMAP_SIZE / 2;
	max_radius = (center - 80) * (center - 80);
	i = 0;
	x = line->player_x;
	y = line->player_y;
	while (i < line->steps)
	{
		if ((((x - center) * (x - center)) + ((y - center)
					* (y - center))) < max_radius)
		{
			if (x >= 5 && x < MINIMAP_SIZE - 5 && y >= 5
				&& y < MINIMAP_SIZE - 5)
				my_mlx_pixel_put(y, x, game, color);
		}	
		x += line->x_incrase;
		y += line->y_incrase;
		i++;
	}
}