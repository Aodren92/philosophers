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
	if (e->display_time <= 0 || e->run)
		return (1);
	return (0);
}

static time_t 	philo_game_timeout_decrement(t_env *env)
{
	time_t 		new_display_time;

	new_display_time = env->end - time(NULL);
	if (env->display_time != new_display_time)
	{
		env->display_time = new_display_time;
		return (1);
	}
	return (0);
}

static void		philo_philosophers_hp_timeout_decrement(t_env *env)
{
	size_t i = 0;
	int 	do_action = 0;

	while (i < 7)
	{
		pthread_mutex_lock(&env->philosophers[i].mutex_timeout);
		env->philosophers[i].timeout -= 1;
		pthread_mutex_unlock(&env->philosophers[i].mutex_timeout);
		pthread_mutex_lock(&env->philosophers[i].mutex_state);
		if (env->philosophers[i].state != STATE_PHILO_EAT)
			do_action = 1;
		pthread_mutex_lock(&env->philosophers[i].mutex_hp);
		if (do_action)
		{
			env->philosophers[i].hp -= DAMAGE_PER_S;
			if (env->philosophers[i].hp <= 0)
			{
				env->victory = DEAD;
				env->run     = 1;
			}
		}
		pthread_mutex_unlock(&env->philosophers[i].mutex_state);
		pthread_mutex_unlock(&env->philosophers[i].mutex_hp);
		do_action = 1;
		i++;
	}
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
		if (e->state && philo_game_timeout_decrement(e))
			philo_philosophers_hp_timeout_decrement(e);
		if (e->state && philo_should_end(e))
			break ;
		philo_renderer(e);
	}
	philo_join_thread(e->philosophers);
	philo_last_screen_loop(e);
	return (NONE);
}
