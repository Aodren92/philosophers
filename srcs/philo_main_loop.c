#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000

/*
** \XXX rename func
*/

static void		philo_renderer(t_env *e)
{
	SDL_RenderClear(e->sys.renderer);
	if (e->state == 1)
	{
		SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, 0, 0);
		philo_display_philosophers(e);
		philo_display_baguettes(e);
		philo_display_text(e);
		SDL_RenderPresent(e->sys.renderer);
		usleep(SECONDE);
		philo_take_damage(e->philosophers);
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

t_err			philo_main_loop(t_env *e)
{
	char	run;
	t_err	err;

	err = NONE;
	run = 1;
	while (run)
	{
		while (SDL_PollEvent(&e->sys.ev))
		{
			if (e->sys.ev.type == SDL_QUIT)
				return (philo_exit(e, NONE));
			else if (e->sys.ev.type == SDL_KEYDOWN)
			{
				if (e->sys.ev.key.keysym.sym == SDLK_ESCAPE)
					return (philo_exit(e, NONE));
				if (e->sys.ev.key.keysym.sym == SDLK_SPACE && e->state == 0)
					philo_start_routine(e);
			}
		}
		if (philo_is_dead(e->philosophers) == DEAD)
			break ;
		philo_renderer(e);
	}
	return (err);
}
