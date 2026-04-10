#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	fov;
}	t_player;

typedef struct s_door
{
	int		x;
	int		y;
	int		frame;
	int		state;
	double	timer;
}	t_door;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	t_door	*doors;
	int		door_count;
}	t_map;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
}	t_texture;

typedef struct s_img
{
	void	*img_ptr;
	int		*buffer;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_minimap
{
	int		x;
	int		y;
	double	map_x;
	double	map_y;
	int		color;
	int		minimap_tile;
	int		size_border;
}	t_minimap;

typedef struct s_milx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*buffer;
	int		bpp;
	int		size_line;
	int		endian;
	int		width_size;
	int		height_size;
}	t_milx;

typedef struct s_keys_move {
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys_move;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	dist_x;
	double	dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	angle;
	double	player_angle;
	double	steps;
	double	text_cur;
	int		steps_x;
	int		steps_y;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		color;
	int		text_y;
	int		text_x;
	double	real_dist;
	int		is_door;
	t_door	*door;
}	t_ray;

typedef struct s_game
{
	t_player		player;
	t_map			map;
	t_texture		texture;
	t_milx			libx;
	t_keys_move		move_keys;
	t_ray			ray[200];
	t_img			walls[4];
	t_img			doors[4][5];
	int				pause_mouse;
}	t_game;

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}					t_line;

typedef struct s_line_calc
{
	int			player_x;
	int			player_y;
	int			end_dir_x;
	int			end_dir_y;
	int			steps;
	int			line_height;
	double		dx;
	double		dy;
	double		x_incrase;
	double		y_incrase;
	double		player_angle;
	double		ray_dir_x;
	double		ray_dir_y;
	double		ray_angle;
}	t_line_calc;

typedef struct s_line_vert
{
	t_img	*wall;
	double	hit_point;
	int		line_h;
	int		start_line;
	int		end_line;
	int		line_height;
}	t_line_vert;

#endif