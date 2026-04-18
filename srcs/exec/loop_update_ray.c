/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_update_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:52:12 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:52:13 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	loop_ray_dda(t_game *game, t_ray *ray)
{
	ray->is_door = 0;
	ray->door = NULL;
	while (!ray->hit)
	{
		update_ray_dist(ray);
		update_ray_hit(game, ray);
	}
}

void	update_ray_hit(t_game *game, t_ray *ray)
{
	t_door	*tmp_door;

	if (ray->map_x < 0 || ray->map_y < 0
		|| ray->map_x >= game->map.width
		|| ray->map_y >= game->map.height)
		ray->hit = 1;
	else if (game->map.grid[ray->map_y][ray->map_x] == '1')
		ray->hit = 1;
	else if (game->map.grid[ray->map_y][ray->map_x] == 'D')
	{
		tmp_door = get_door(game, ray->map_x, ray->map_y);
		if (tmp_door && tmp_door->frame < 5)
		{
			ray->hit = 1;
			ray->is_door = 1;
			ray->door = tmp_door;
		}
	}
}

void	update_ray_dist(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->steps_x;
		if (ray->dir_x > 0)
			ray->side = 0;
		else
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->steps_y;
		if (ray->dir_y > 0)
			ray->side = 2;
		else
			ray->side = 3;
	}
}
