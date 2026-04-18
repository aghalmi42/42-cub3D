/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <amoderan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:57:10 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/16 13:16:24 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "struct.h"

/* init */

int		init_milx(t_milx *var, t_game *game);
int		free_mlx_and_destroy(t_game *game);
void	free_texture_ptr(t_game *game);
void	init_move_keys(t_game *game);
void	my_mlx_pixel_put(int y, int x, t_game *game, int color);
void	handle_error_init_textures(void	*img, char *name_texture, t_game *game);
int		init_everything(t_game *game);
char	*init_path_one_door_frame(char *prefixes[4], int frame, int side);
void	send_textures_to_buffer(t_game *game);
void	init_textures(t_game *game);

/* hooks */

int		handle_input(int keycode, t_game *game);
int		keys_move_press(int keycode, t_game *game);
int		keys_move_release(int keycode, t_game *game);
int		mouse_shift(int x, int y, t_game *game);
void	pause_mouse(t_game *game);

/* move */

void	move_player(t_game *game);
int		update_game(t_game *game);
void	update_move_player(t_game *game);
int		can_move(t_game *game, double x, double y);
void	update_camera_shifting(t_game *game, double shift);
void	update_new_coords(double *new_x, double *new_y,
			t_game *game, double move);

/* display */

void	display_square(t_game *game, double x, double y);
void	display_player_direction(t_game *game);
void	display_line(t_game *game, t_line_calc *line, int color);
void	display_vertical_line_with_textures(t_game *game, int x,
			t_ray *ray, t_line_vert line);
void	loop_display_vert_line_with_textures(t_game *game,
			t_ray *ray, t_line_vert *line, int x);
void	set_wall_img(t_game *game, t_ray *ray, t_line_vert *line);
void	set_hit_point(t_game *game, t_ray *ray, t_line_vert *line);
void	set_text_x(t_ray *ray, double hit_point, t_img *wall);
double	value_of_wall_x(t_game *game, t_ray *ray);

/* raycasting */

void	loop_ray_2D(t_game *game);
void	dda(t_game *game, int minimap);
void	init_ray_dda(t_game *game, double i, t_ray *ray, int minimap);
void	calc_steps_and_side_dist(t_game *game, t_ray *ray);
void	loop_ray_dda(t_game *game, t_ray *ray);
void	display_ray(t_game *game, t_ray *ray);
void	update_ray_dist(t_ray *ray);
void	update_ray_hit(t_game *game, t_ray *ray);
void	init_ray_dda_minimap(t_game *game, t_ray *ray, int minimap, double i);

/* minimap */

void	display_minimap(t_game *game);
void	display_border_minimaap(t_minimap mmap, t_game *game, int i);
void	display_multiple_border_minimap(t_minimap mmap, t_game *game);
void	display_player_minimap(t_game *game);
void	display_ray_on_minimap(t_game *game, t_ray *ray);
void	display_line_minimap(t_game *game, t_line_calc *line, int color);
void	set_color_minimap(t_game *game, t_minimap *mmap);

/* 3D */

void	raycasting_to_3d(t_game *game);
double	value_of_wall_x(t_game *game, t_ray *ray);
int		apply_shadow(int color, double distance);

/* doors */

void	init_prefixes(char *prefixes[4]);
int		init_one_door_frame(t_game *game, int side, int frame,
			char *prefixes[4]);
int		init_all_doors(t_game *game);
t_door	*get_door(t_game *game, int x, int y);
void	update_door(t_game *game);
void	interact_with_door(t_game *game);
#endif