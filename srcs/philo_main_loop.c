#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000

/*
** \XXX rename func
*/

static void		philo_renderer(t_env *e)
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

static void		philo_last_screen_renderer(t_env *e)
{
	SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, 0, 0);
	philo_display_philosophers(e);
	philo_display_baguettes(e);
	philo_display_text(e);
	philo_display_timeout(e);
	philo_display_conclusion(e);
	SDL_RenderPresent(e->sys.renderer);
}

static t_err	philo_last_screen_loop(t_env *e)
{
	while (1)
	{
		while (SDL_PollEvent(&e->sys.ev))
		{
			if (e->sys.ev.type == SDL_QUIT)
				return (philo_exit_gfx(e, NONE));
			else if (e->sys.ev.type == SDL_KEYDOWN)
			{
				if (e->sys.ev.key.keysym.sym == SDLK_ESCAPE)
					return (philo_exit_gfx(e, NONE));
			}
		}
		philo_last_screen_renderer(e);
	}
	return (NONE);
}

static int		philo_should_end(t_env *e)
{
	if (e->end <= time(NULL))
		return (1);
	return (0);
}

t_err			philo_main_loop(t_env *e)
{
	while (1)
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
		philo_renderer(e);
		if ((e->victory = philo_is_dead(e->philosophers)) == DEAD)
			break ;
		if (e->state && philo_should_end(e))
			break ;
	}
	philo_join_thread(e->philosophers);
	philo_last_screen_loop(e);
	return (NONE);
}
