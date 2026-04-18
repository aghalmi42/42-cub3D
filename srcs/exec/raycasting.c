/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:15 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:16 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(t_game *game, int minimap)
{
	int		i;
	double	angle;

	i = 0;
	angle = 0;
	while (i < 60)
	{
		init_ray_dda(game, i, &game->ray[i], minimap);
		i++;
		angle += 60 / (double)game->libx.width_size;
	}
}

void	init_ray_dda(t_game *game, double i, t_ray *ray, int minimap)
{
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->hit = 0;
	init_ray_dda_minimap(game, ray, minimap, i);
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = 1 / fabs(ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = 1 / fabs(ray->dir_y);
	calc_steps_and_side_dist(game, ray);
	loop_ray_dda(game, ray);
	if (ray->side == 0 || ray->side == 1)
		ray->real_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->real_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (minimap)
		display_ray_on_minimap(game, ray);
}

void	init_ray_dda_minimap(t_game *game, t_ray *ray, int minimap, double i)
{
	if (minimap)
	{
		ray->player_angle = atan2(game->player.dir_y, game->player.dir_x);
		ray->angle = ray->player_angle - (30 * M_PI / 180.0)
			+ (i * M_PI / 180.0);
		ray->dir_x = cos(ray->angle);
		ray->dir_y = sin(ray->angle);
	}
}

void	calc_steps_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->steps_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->steps_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - game->player.x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->steps_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->steps_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - game->player.y)
			* ray->delta_dist_y;
	}
}

t_door	*get_door(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map.door_count)
	{
		if (game->map.doors[i].x == x && game->map.doors[i].y == y)
			return (&game->map.doors[i]);
		i++;
	}
	return (NULL);
}
