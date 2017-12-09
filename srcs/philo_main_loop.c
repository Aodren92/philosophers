#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000

/*
** \XXX rename func
*/

static void		philo_renderer(t_env *e)
{
	SDL_RenderClear(e->sys.renderer);
	SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, NULL, NULL);
	philo_display_philosophers(e);
	philo_display_baguettes(e);
	SDL_RenderPresent(e->sys.renderer);
	usleep(SECONDE);
	philo_take_damage(e->philosophers);
	philo_display_philo_console(e->philosophers);
}

t_err			philo_main_loop(t_env *e)
{
	char	run;
	t_err	err;

	err = NONE;
	philo_start_routine(e);
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
			}
		}
		philo_renderer(e);
		if (philo_is_dead(e->philosophers) == DEAD)
			break ;
	}
	return (err);
}
