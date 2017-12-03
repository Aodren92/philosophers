#include "philosophers.h"

# define DEBUG_POS_NORM 0
# define DEBUG_POS_RIGHT 7
# define DEBUG_POS_LEFT 14

void	philo_display_baguettes(t_env *e)
{
	unsigned int i;

	i = 8;
	while (i < 15)
	{
		SDL_RenderCopyEx(e->sys.renderer, e->texture[i].tex,
				&e->texture[i].rect_s, &e->pos[i + DEBUG_POS_RIGHT].rect_d,
				e->pos[i + DEBUG_POS_RIGHT].angle, e->pos[i + DEBUG_POS_RIGHT].center,
				0);
		++i;
	}
}
