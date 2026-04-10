#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "struct_bonus.h"

t_line  *add_line(t_line *lst, char *content);
int		count_line(t_line *lst);
void	free_lst(t_line *lst);
char	**convert_lst_to_array(t_line *lst, int size);
int		check_extension(char *file_name);
int		open_file(char *file_name);
t_line	*processus_of_line(t_line *lst, char *line);
t_line	*read_line(int fd);
char	**read_file_to_array(char *file_name);
char	*copy_line(char *line, int width);
void	free_part_grid(char **grid, int line);
char	**copy_grid(t_map *map);
void	free_grid(char **grid);
int		check_valid_element(t_map *map);
void	count_element(t_map *map, int *player_count);
int		valid_map(t_game *game);
int		flood_fill(char **grid, int x, int y, t_map *map);
int		check_flood_result(t_map *map, char **grid);
int		valid_track(t_game *game);
int		find_start_map(char **array);
int		parsing_texture_id(char *line, t_game *game);
int		parsing_color_id(char *line, t_game *game);
int		parsing_line(char *line, t_game *game);
int		parsing_element(char **array, int map_start, t_game *game);
int		check_all_element(t_game *game);
char	*parsing_texture(char *line);
int		parsing_color(char *line);
void	init_game(t_game *game);
void	map_dimension(char **array, int map_start, t_game *game);
int		malloc_grid(t_game *game);
void	set_dir_ns(char c, t_game *game);
void	set_dir_ew(char c, t_game *game);
void	set_dir_player(char c, t_game *game);
int		is_player(char c);
void	find_player(char *line, int y, t_game *game);
int		fill_grid(char **array, int map_start, t_game *game);
int		parsing_map(char **array, int map_start, t_game *game);
int		check_extension_xpm(char *path);
int		check_file_exist(char *path);
int		check_texture(char *path);
int		check_all_texture(t_texture *texture);
void	clean_line(char *line);
void	clean_array(char **array);
char	*formate_line(char *line, int width);
int		formate_map(t_game *game);
void	count_door(t_game *game);
int		malloc_door(t_game *game);
void	fill_door(t_game *game);
int		parsing_door(t_game *game);
void	free_texture(t_texture *texture);
void	free_door(t_map *map);
void	free_game(t_game *game);

#endif