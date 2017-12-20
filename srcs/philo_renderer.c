#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000

void		philo_renderer(t_env *e)
{
	if (e->state == 1)
	{
		SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, 0, 0);
		philo_display_philosophers(e);
		philo_display_baguettes(e);
		philo_display_text(e);
		philo_display_timeout(e);
		SDL_RenderPresent(e->sys.renderer);
	}
	else
	{
		usleep(SECONDE / 2);
		SDL_RenderCopy(e->sys.renderer, e->start[0].tex, 0, 0);
		SDL_RenderCopy(e->sys.renderer, e->start[1].tex, 0,
				&e->start[1].rect_d);
		SDL_RenderPresent(e->sys.renderer);
		usleep(SECONDE / 2);
		SDL_RenderCopy(e->sys.renderer, e->start[0].tex, 0, 0);
		SDL_RenderPresent(e->sys.renderer);
	}
}

void		philo_last_screen_renderer(t_env *e)
{
	SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, 0, 0);
	philo_display_philosophers(e);
	philo_display_baguettes(e);
	philo_display_text(e);
	philo_display_timeout(e);
	philo_display_conclusion(e);
	SDL_RenderPresent(e->sys.renderer);
}
