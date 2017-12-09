#include "philosophers.h"

void	philo_init_system(t_system *sys)
{
	sys->win = 0;
	sys->renderer = 0;
	//sys->bitmaptex = 0;
}

t_err	philo_init_env(t_env *e)
{
	e->win.width = 1280;
	e->win.height = 720;
	if ((e->sys.win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win.width, e->win.height,
			0)) == NULL)
		return (E_WINDOW);
	if ((e->sys.renderer = SDL_CreateRenderer(e->sys.win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
		return (E_RENDERER);
	return (NONE);
}


static void	philo_init_name(t_philosphers *philo)
{
	ft_strcpy(philo[0].name, "name 0");
	ft_strcpy(philo[1].name, "name 1");
	ft_strcpy(philo[2].name, "name 2");
	ft_strcpy(philo[3].name, "name 3");
	ft_strcpy(philo[4].name, "name 4");
	ft_strcpy(philo[5].name, "name 5");
	ft_strcpy(philo[6].name, "name 6");
}

void	philo_init_philosophers(t_env *env)
{
	unsigned int i;
	i = 0;

	while (i < 7)
	{
		env->philosophers[i].hp = MAX_LIFE;
		env->philosophers[i].state = STATE_PHILO_REST;
		env->philosophers[i].baguette.pos = POS_BAGUETTE_NOR;
		//\XXX use pthread_mutex_init
		env->philosophers[i].mutex_hp = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_right = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_left = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_b_right
			= (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_b_left = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_state = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].mutex_timeout = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		env->philosophers[i].timeout = REST_T;


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
	philo_init_name(env->philosophers);
}


t_err	philo_init_display(t_env *env)
{
	SDL_Surface *bitmapSurface[8] = {0};

	if (!(bitmapSurface[0] = SDL_LoadBMP("./res/background.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[0].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[0])))
		return (E_INIT);
	SDL_FreeSurface(bitmapSurface[1]);
	philo_add_philos(env);
	return (NONE);
}

t_err	philo_init_baguette(t_env *env)
{
	return (philo_add_baguettes(env));
}
