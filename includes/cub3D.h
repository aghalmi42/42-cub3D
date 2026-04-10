#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include "struct.h"
# include "parsing.h"
# include "exec.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_Z 122
# define KEY_E 101
# define KEY_P 112
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define BLACK 0x000000
# define DARK_BLUE 0x000040
# define BLUE 0x0000FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF
# define ORANGE 0xF2850D
# define RED 0x9D2933
# define GREEN 0x008000
# define YELLOW 0xFFDE21

# define TILE_SIZE 32
# define M_PI       3.14159265358979323846

# define MINIMAP_SIZE 200
# define MINIMAP_RANGE 5

#endif