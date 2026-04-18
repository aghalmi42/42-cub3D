/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:56:50 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:56:51 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "struct_bonus.h"

int		parsing(t_game *game, int ac, char **av);
int		parsing_first_part(t_game *game, char **array, int map_start);

/* set elements for parsing */

int		set_parsing_elements(t_game *game, char ***array,
			int *map_start, char **av);
void	init_game(t_game *game);
char	**read_file_to_array(char *file_name);
int		is_clean_array(char **array);
int		is_clean_line(char *line);
int		open_file(char *file_name);
int		check_extension(char *file_name);
t_line	*processus_of_line(t_line *lst, char *line);
t_line	*read_line(int fd);
t_line	*add_line(t_line *lst, char *content);
int		count_line(t_line *lst);
char	**convert_lst_to_array(t_line *lst, int size);
void	free_lst(t_line *lst);
int		find_start_map(char **array);
int		check_start_map(char c, char d);

/* parse elements except map */

int		parsing_element(char **array, int map_start, t_game *game);
int		parsing_texture_id(char *line, t_game *game);
int		parsing_color_id(char *line, t_game *game);
int		parsing_line(char *line, t_game *game);
int		check_all_element(t_game *game);
int		pass_spaces_in_line(char *line);
int		parsing_texture_id_two(char *line, t_game *game, int i);
char	*parsing_texture(char *line, int i);
int		parsing_color(char *line, int i);
int		parsing_color_id_two(char *line, t_game *game, int i);
int		color_to_return(char **rgb);
int		check_commas(char *line, int i);
int		check_numeric_rgb(char **rgb);
char	**rgb_split_to_return(char *line, int i);

/* check textures */

int		check_extension_xpm(char *path);
int		check_file_exist(char *path);
int		check_texture(char *path);
int		check_all_texture(t_texture *texture);

/* start parse map */

int		parsing_map(char **array, int map_start, t_game *game);
void	map_dimension(char **array, int map_start, t_game *game);
int		check_empty_lines_in_map(char **array, int map_start);
int		malloc_grid(t_game *game);
int		fill_grid(char **array, int map_start, t_game *game);
void	set_dir_ns(char c, t_game *game);
void	set_dir_ew(char c, t_game *game);
void	set_dir_player(char c, t_game *game);
int		is_player(char c);
void	find_player(char *line, int y, t_game *game);

/* formate map */

char	*formate_line(char *line, int width);
int		formate_map(t_game *game);

/* valid map */

int		valid_map(t_game *game);
int		check_valid_element(t_map *map);
int		valid_track(t_game *game);
void	count_element(t_map *map, int *player_count);
char	*copy_line(char *line, int width);
void	free_part_grid(char **grid, int line);
char	**copy_grid(t_map *map);
void	free_grid(char **grid);
int		flood_fill(char **grid, int x, int y, t_map *map);
int		check_flood_result(t_map *map, char **grid);

/* free */

void	free_texture(t_texture *texture);
void	free_game(t_game *game);

/* door parsing */

int		parsing_door(t_game *game);
void	fill_door(t_game *game);
int		malloc_door(t_game *game);
void	count_door(t_game *game);
#endif