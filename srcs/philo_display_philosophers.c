#include "philosophers.h"

void	philo_display_philosophers(t_env *e)
{
	unsigned int i;

	i = 0;
	while (i < 8)
	{
		SDL_RenderCopyEx(e->sys.renderer, e->texture[i].tex,
				&e->texture[i].rect_s, &e->pos[i].rect_d,
				e->pos[i].angle, e->pos[i].center,
				0);
		++i;
	}
}
