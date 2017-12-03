#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000
t_err			philo_main_loop(t_env *e)
{
	char	run = 1;
	t_err	err = NONE;

	(void)err;
	philo_start_routine(e);
	while (run)
	{
		while (SDL_PollEvent(&e->sys.ev))
		{
			if (e->sys.ev.type == SDL_QUIT)
			{
				//\XXX KILL THREADS
				return (philo_exit(e, NONE));
			}
			else if (e->sys.ev.type == SDL_KEYDOWN)
			{
				if (e->sys.ev.key.keysym.sym == SDLK_ESCAPE)
				{
					//\XXX KILL THREADS
					return (philo_exit(e, NONE));
				}
			}
		}
		SDL_RenderClear(e->sys.renderer);
		SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, NULL, NULL);
		philo_display_philosophers(e);
		philo_display_baguettes(e);
		SDL_RenderPresent(e->sys.renderer);
		usleep(SECONDE);
		philo_take_damage(e->philosophers);
		if (philo_is_dead(e->philosophers) == DEAD)
			break ;
	}
	return (err);
}
