#include "../../includes_bonus/cub3D_bonus.h"

void	display_ray(t_game *game, t_ray *ray)
{
	t_line_calc	line;

	line.player_angle = atan2(game->player.dir_y, game->player.dir_x);
	line.player_x = game->player.x * TILE_SIZE;
	line.player_y = game->player.y * TILE_SIZE;
	line.ray_angle = ray->angle;
	line.ray_dir_x = cos(line.ray_angle);
	line.ray_dir_y = sin(line.ray_angle);
	line.end_dir_x = (game->player.x + ray->dir_x * ray->real_dist) * TILE_SIZE;
	line.end_dir_y = (game->player.y + ray->dir_y * ray->real_dist) * TILE_SIZE;
	line.dx = line.end_dir_x - line.player_x;
	line.dy = line.end_dir_y - line.player_y;
	if (fabs(line.dx) > fabs(line.dy))
		line.steps = fabs(line.dx);
	else
		line.steps = fabs(line.dy);
	line.x_incrase = line.dx / (double)line.steps;
	line.y_incrase = line.dy / (double)line.steps;
	display_line(game, &line, WHITE);
}

void	display_ray_on_minimap(t_game *game, t_ray *ray)
{
	t_line_calc	line;
	double		mmap_scale;

	mmap_scale = (double)MINIMAP_SIZE / (MINIMAP_RANGE * 2);
	line.player_x = MINIMAP_SIZE / 2;
	line.player_y = MINIMAP_SIZE / 2;
	line.end_dir_x = line.player_x + (ray->dir_x * ray->real_dist) * mmap_scale;
	line.end_dir_y = line.player_y + (ray->dir_y * ray->real_dist) * mmap_scale;
	line.dx = line.end_dir_x - line.player_x;
	line.dy = line.end_dir_y - line.player_y;
	if (fabs(line.dx) > fabs(line.dy))
		line.steps = fabs(line.dx);
	else
		line.steps = fabs(line.dy);
	line.x_incrase = line.dx / (double)line.steps;
	line.y_incrase = line.dy / (double)line.steps;
	display_line_minimap(game, &line, WHITE);
}
