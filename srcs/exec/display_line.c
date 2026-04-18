/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:51:22 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:51:23 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	display_vertical_line_with_textures(t_game *game, int x,
		t_ray *ray, t_line_vert line)
{
	set_wall_img(game, ray, &line);
	set_hit_point(game, ray, &line);
	set_text_x(ray, line.hit_point, line.wall);
	line.line_h = (int)(game->libx.height_size / ray->real_dist);
	ray->steps = 1.0 * line.wall->height / line.line_h;
	ray->text_cur = (line.start_line - game->libx.height_size / 2
			+ line.line_h / 2) * ray->steps;
	loop_display_vert_line_with_textures(game, ray, &line, x);
}

void	loop_display_vert_line_with_textures(t_game *game, t_ray *ray,
		t_line_vert *line, int x)
{
	int	y;

	y = 0;
	while (y < game->libx.height_size)
	{
		if (y < line->start_line)
			my_mlx_pixel_put(y, x, game, game->texture.ceiling);
		else if (y >= line->start_line && y <= line->end_line)
		{
			ray->text_y = (int)ray->text_cur % line->wall->height;
			if (ray->text_y < 0)
				ray->text_y += line->wall->height;
			ray->text_cur += ray->steps;
			ray->color = line->wall->buffer[line->wall->width
				* ray->text_y + ray->text_x];
			my_mlx_pixel_put(y, x, game, ray->color);
		}
		else
			my_mlx_pixel_put(y, x, game, game->texture.floor);
		y++;
	}
}
