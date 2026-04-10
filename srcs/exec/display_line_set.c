#include "../../includes/cub3D.h"

void	set_wall_img(t_game *game, t_ray *ray, t_line_vert *line)
{
	if (ray->is_door && ray->door)
		line->wall = &game->doors[ray->side][ray->door->frame];
	else
		line->wall = &game->walls[ray->side];
}

void	set_hit_point(t_game *game, t_ray *ray, t_line_vert *line)
{
	if (ray->side == 0 || ray->side == 1)
		line->hit_point = game->player.y + ray->real_dist * ray->dir_y;
	else
		line->hit_point = game->player.x + ray->real_dist * ray->dir_x;
	line->hit_point -= floor(line->hit_point);
}

void	set_text_x(t_ray *ray, double hit_point, t_img *wall)
{
	ray->text_x = (int)(hit_point * (double)wall->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 3 && ray->dir_y < 0))
		ray->text_x = wall->width - ray->text_x - 1;
	if ((ray->side == 1 && ray->dir_x < 0)
		|| (ray->side == 2 && ray->dir_y > 0))
		ray->text_x = wall->width - ray->text_x - 1;
	if (ray->text_x < 0)
		ray->text_x = 0;
	if (ray->text_x >= wall->width)
		ray->text_x = wall->width - 1;
}
