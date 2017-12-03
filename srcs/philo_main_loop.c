#include "philosophers.h"
#include <time.h>

#define SECONDE 1 * 1000 * 1000
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
				return (philo_exit(e, NONE));
			}
			else if (e->sys.ev.type == SDL_WINDOWEVENT)
			{
#if 0
				if (e->ev.window.event == SDL_WINDOWEVENT_RESIZED)
					if ((err = philo_resize_window(&(e->var), e->win,
									&(e->fractal), &(e->ev))) != NONE)
					{
						return philo_exit(e, err);
					}
#endif
			}
			else if (e->sys.ev.type == SDL_KEYDOWN)
			{
				if (e->sys.ev.key.keysym.sym == SDLK_ESCAPE)
				{
					return (philo_exit(e, NONE));
				}
			}
			SDL_RenderClear(e->sys.renderer);
			SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, NULL, NULL);
			philo_display_philosophers(e);
			philo_display_baguettes(e);
			SDL_RenderPresent(e->sys.renderer);
#if 0
			if (e->var.render == 1)
				if ((err = philo_draw_fractal(e)) != NONE)
				{
					philo_exit(e, &run, err);
					break;
				}
#endif
		}
	}
	return (err);
}
