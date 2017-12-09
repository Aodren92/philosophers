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

	SDL_FreeSurface(bitmapSurface[0]);
	if (!(bitmapSurface[1] = SDL_LoadBMP("./res/trump.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[1],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[1]->format, 0, 255, 0));
	if (!(env->texture[1].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[1])))


	SDL_FreeSurface(bitmapSurface[1]);

	if (!(bitmapSurface[2] = SDL_LoadBMP("./res/poutin2.bmp")))
		return (E_TEXTURE);
		#if 1
	SDL_SetColorKey(bitmapSurface[2],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[2]->format, 0, 255, 0));
	#endif
	if (!(env->texture[2].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[2])))

	SDL_FreeSurface(bitmapSurface[2]);

	if (!(bitmapSurface[3] = SDL_LoadBMP("./res/ben_laden.bmp")))
		return (E_TEXTURE);

	SDL_SetColorKey(bitmapSurface[3],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[3]->format, 0, 255, 0));

	if (!(env->texture[3].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[3])))
	SDL_FreeSurface(bitmapSurface[3]);

	if (!(bitmapSurface[4] = SDL_LoadBMP("./res/syler.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[4],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[4]->format, 0, 255, 0));
	if (!(env->texture[4].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[4])))
	SDL_FreeSurface(bitmapSurface[4]);

	if (!(bitmapSurface[5] = SDL_LoadBMP("./res/kim.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[5],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[5]->format, 0, 255, 0));
	if (!(env->texture[5].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[5])))
	SDL_FreeSurface(bitmapSurface[5]);

	if (!(bitmapSurface[6] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[6].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[6])))
	SDL_FreeSurface(bitmapSurface[6]);

	if (!(bitmapSurface[7] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[7].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[7])))
	SDL_FreeSurface(bitmapSurface[7]);
	return (NONE);
}


t_err	philo_init_rect(t_env *env)
{
	//philosophers
	env->texture[1].rect_s.x = 0;
	env->texture[1].rect_s.y = 0;
	env->texture[1].rect_s.w = 950;
	env->texture[1].rect_s.h = 346;
	env->texture[1].pos = 1;


	env->texture[2].rect_s.x = 0;
	env->texture[2].rect_s.y = 0;
	env->texture[2].rect_s.w = 150;
	env->texture[2].rect_s.h = 150;
	env->texture[2].pos = 2;


	env->texture[3].rect_s.x = 0;
	env->texture[3].rect_s.y = 0;
	env->texture[3].rect_s.w = 2000;
	env->texture[3].rect_s.h = 1312;
	env->texture[3].pos = 3;

	env->texture[4].rect_s.x = 250;
	env->texture[4].rect_s.y = 0;
	env->texture[4].rect_s.w = 865;
	env->texture[4].rect_s.h = 1540;
	env->texture[4].pos = 4;


	env->texture[5].rect_s.x = 250;
	env->texture[5].rect_s.y = 0;
	env->texture[5].rect_s.w = 1280;
	env->texture[5].rect_s.h = 720;
	env->texture[5].pos = 5;

	env->texture[6].rect_s.x = 0;
	env->texture[6].rect_s.y = 0;
	env->texture[6].rect_s.w = 150;
	env->texture[6].rect_s.h = 150;
	env->texture[5].pos = 6;

	env->texture[7].rect_s.x = 0;
	env->texture[7].rect_s.y = 0;
	env->texture[7].rect_s.w = 150;
	env->texture[7].rect_s.h = 150;
	env->texture[5].pos = 7;

		// baguettes
	env->texture[8].rect_s.x = 40;
	env->texture[8].rect_s.y = 0;
	env->texture[8].rect_s.w = 564;
	env->texture[8].rect_s.h = 1168;
	env->texture[8].pos = 8;


	env->texture[9].rect_s.x = 40;
	env->texture[9].rect_s.y = 0;
	env->texture[9].rect_s.w = 564;
	env->texture[9].rect_s.h = 1168;
	env->texture[9].pos = 9;

	env->texture[10].rect_s.x = 40;
	env->texture[10].rect_s.y = 0;
	env->texture[10].rect_s.w = 564;
	env->texture[10].rect_s.h = 1168;
	env->texture[10].pos = 10;

	env->texture[11].rect_s.x = 40;
	env->texture[11].rect_s.y = 0;
	env->texture[11].rect_s.w = 564;
	env->texture[11].rect_s.h = 1168;
	env->texture[11].pos = 11;

	env->texture[12].rect_s.x = 40;
	env->texture[12].rect_s.y = 0;
	env->texture[12].rect_s.w = 564;
	env->texture[12].rect_s.h = 1168;
	env->texture[12].pos = 12;

	env->texture[13].rect_s.x = 40;
	env->texture[13].rect_s.y = 0;
	env->texture[13].rect_s.w = 564;
	env->texture[13].rect_s.h = 1168;
	env->texture[13].pos = 13;

	env->texture[14].rect_s.x = 40;
	env->texture[14].rect_s.y = 0;
	env->texture[14].rect_s.w = 564;
	env->texture[14].rect_s.h = 1168;
	env->texture[14].pos = 14;
	return (NONE);
}



t_err	philo_init_baguette(t_env *env)
{
	(void)env;
	SDL_Surface *bitmapSurface[7] = {0};

	if (!(bitmapSurface[0] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[0],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[0]->format, 255, 255, 255));
	if (!(env->texture[8].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[0])))

	SDL_FreeSurface(bitmapSurface[0]);

	if (!(bitmapSurface[1] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[1],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[1]->format, 255, 255, 255));
	if (!(env->texture[9].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[1])))
	SDL_FreeSurface(bitmapSurface[1]);

	if (!(bitmapSurface[2] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[2],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[2]->format, 255, 255, 255));
	if (!(env->texture[10].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[2])))

	SDL_FreeSurface(bitmapSurface[2]);

	if (!(bitmapSurface[3] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[3],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[3]->format, 255, 255, 255));
	if (!(env->texture[11].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[3])))
	SDL_FreeSurface(bitmapSurface[3]);

	if (!(bitmapSurface[4] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[4],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[4]->format, 255, 255, 255));
	if (!(env->texture[12].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[4])))
	SDL_FreeSurface(bitmapSurface[4]);

	if (!(bitmapSurface[5] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[5],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[5]->format, 255, 255, 255));
	if (!(env->texture[13].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[5])))
	SDL_FreeSurface(bitmapSurface[5]);

	if (!(bitmapSurface[6] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface[6],
			SDL_TRUE, SDL_MapRGB(bitmapSurface[6]->format, 255, 255, 255));
	if (!(env->texture[14].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[6])))
	SDL_FreeSurface(bitmapSurface[6]);
	return (NONE);
}
