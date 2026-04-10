#include "../../includes_bonus/cub3D_bonus.h"

int	update_game(t_game *game)
{
	update_move_player(game);
	update_camera_shifting(game, -0.005);
	update_door(game);
	raycasting_to_3d(game);
	display_minimap(game);
	return (0);
}

void	update_door(t_game *game)
{
	int		i;
	t_door	*d;

	i = 0;
	while (i < game->map.door_count)
	{
		d = &game->map.doors[i];
		if (d->state == 1 || d->state == 3)
		{
			d->timer += 1;
			if (d->timer >= 100)
			{
				if (d->state == 1 && d->frame < 5)
					d->frame++;
				else if (d->state == 3 && d->frame > 0)
					d->frame--;
				if (d->state == 1 && d->frame == 5)
					d->state = 2;
				else if (d->state == 3 && d->frame == 0)
					d->state = 0;
				d->timer = 0;
			}
		}
		i++;
	}
}
