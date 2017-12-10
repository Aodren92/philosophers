#include "philosophers.h"


void	philo_display_txt(t_env *e)
{
	SDL_RenderCopyEx(e->sys.renderer, e->txt[0].tex,
			&e->txt[0].rect_s, &e->txt[0].rect_d,
			0, 0, 0);
}
