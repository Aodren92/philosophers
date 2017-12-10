#include "philosophers.h"

void		philo_init_system(t_system *sys)
{
	sys->win = 0;
	sys->renderer = 0;
}

t_err		philo_init_env(t_env *e)
{
	e->win.width = 1280;
	e->win.height = 720;
	e->state = 0;
	if ((e->sys.win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, e->win.width, e->win.height,
					0)) == NULL)
		return (E_WINDOW);
	if ((e->sys.renderer = SDL_CreateRenderer(e->sys.win, -1,
					SDL_RENDERER_ACCELERATED
					| SDL_RENDERER_PRESENTVSYNC)) == NULL)
		return (E_RENDERER);
	return (NONE);
}

/*
** \XXX will be removed for one mutex
*/

static void	philo_init_mutex(t_env *env, int philo)
{
	pthread_mutex_init(&env->philosophers[philo].baguette.mutex_baguette,
			0);
}

void		philo_init_philosophers(t_env *env)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
		env->philosophers[i].hp = MAX_LIFE;
		env->philosophers[i].state = STATE_PHILO_REST;
		env->philosophers[i].baguette.pos = POS_BAGUETTE_NOR;
		env->philosophers[i].timeout = REST_T;
		philo_init_mutex(env, i);
		if (i == 6)
			env->philosophers[i].left = &env->philosophers[0];
		else
			env->philosophers[i].left = &env->philosophers[i + 1];
		if (i > 0)
			env->philosophers[i].right = &env->philosophers[i - 1];
		else
			env->philosophers[i].right = &env->philosophers[6];
		++i;
	}
}

t_err		philo_init_display(t_env *env)
{
	SDL_Surface *bitmapsurface[8];

	if (!(bitmapsurface[0] = SDL_LoadBMP("./res/background.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[0].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
					bitmapsurface[0])))
		return (E_INIT);
	SDL_FreeSurface(bitmapsurface[1]);
	philo_add_philos(env);
	return (NONE);
}
