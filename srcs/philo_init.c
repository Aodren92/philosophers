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
	//fractol_reset_view(&(e->var));
	if ((e->sys.win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win.width, e->win.height,
			0)) == NULL)
		return (E_WINDOW);
	if ((e->sys.renderer = SDL_CreateRenderer(e->sys.win, -1, SDL_RENDERER_ACCELERATED)) == NULL)
		return (E_RENDERER);
/*
	if ((e->fractal.surf = SDL_CreateRGBSurface(0, e->var.win_width, e->var.win_height,
			32, 0, 0, 0, 0)) == NULL)
		return (E_SURFACE);
*/
	return (NONE);
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
	if (!(bitmapSurface[1] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[1].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[1])))


	SDL_FreeSurface(bitmapSurface[1]);

	if (!(bitmapSurface[2] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[2].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[2])))

	SDL_FreeSurface(bitmapSurface[2]);

	if (!(bitmapSurface[3] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[3].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[3])))
	SDL_FreeSurface(bitmapSurface[3]);

	if (!(bitmapSurface[4] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[4].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[4])))
	SDL_FreeSurface(bitmapSurface[4]);

	if (!(bitmapSurface[5] = SDL_LoadBMP("./res/poutin.bmp")))
		return (E_TEXTURE);
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
	env->texture[1].rect_s.x = 0;
	env->texture[1].rect_s.y = 0;
	env->texture[1].rect_s.w = 150;
	env->texture[1].rect_s.h = 150;
	env->texture[1].rect_d.x = 380;
	env->texture[1].rect_d.y = 290;
	env->texture[1].rect_d.w = 70;
	env->texture[1].rect_d.h = 75;
	env->texture[1].angle = 0;
	env->texture[1].center = 0;

	env->texture[2].rect_s.x = 0;
	env->texture[2].rect_s.y = 0;
	env->texture[2].rect_s.w = 150;
	env->texture[2].rect_s.h = 150;
	env->texture[2].rect_d.x = 600;
	env->texture[2].rect_d.y = 220;
	env->texture[2].rect_d.w = 70;
	env->texture[2].rect_d.h = 75;
	env->texture[2].angle = 0;
	env->texture[2].center = 0;

	env->texture[3].rect_s.x = 0;
	env->texture[3].rect_s.y = 0;
	env->texture[3].rect_s.w = 150;
	env->texture[3].rect_s.h = 150;
	env->texture[3].rect_d.x = 190;
	env->texture[3].rect_d.y = 340;
	env->texture[3].rect_d.w = 70;
	env->texture[3].rect_d.h = 75;
	env->texture[3].angle = 0;
	env->texture[3].center = 0;

	env->texture[4].rect_s.x = 0;
	env->texture[4].rect_s.y = 0;
	env->texture[4].rect_s.w = 150;
	env->texture[4].rect_s.h = 160;
	env->texture[4].rect_d.x = 140;
	env->texture[4].rect_d.y = 440;
	env->texture[4].rect_d.w = 80;
	env->texture[4].rect_d.h = 85;
	env->texture[4].angle = 0;
	env->texture[4].center = 0;

	env->texture[5].rect_s.x = 0;
	env->texture[5].rect_s.y = 0;
	env->texture[5].rect_s.w = 150;
	env->texture[5].rect_s.h = 150;
	env->texture[5].rect_d.x = 850;
	env->texture[5].rect_d.y = 285;
	env->texture[5].rect_d.w = 70;
	env->texture[5].rect_d.h = 75;
	env->texture[5].angle = 0;
	env->texture[5].center = 0;

	env->texture[6].rect_s.x = 0;
	env->texture[6].rect_s.y = 0;
	env->texture[6].rect_s.w = 150;
	env->texture[6].rect_s.h = 150;
	env->texture[6].rect_d.x = 1070;
	env->texture[6].rect_d.y = 330;
	env->texture[6].rect_d.w = 70;
	env->texture[6].rect_d.h = 75;
	env->texture[6].angle = 0;
	env->texture[6].center = 0;

	env->texture[7].rect_s.x = 0;
	env->texture[7].rect_s.y = 0;
	env->texture[7].rect_s.w = 150;
	env->texture[7].rect_s.h = 150;
	env->texture[7].rect_d.x = 1130;
	env->texture[7].rect_d.y = 450;
	env->texture[7].rect_d.w = 80;
	env->texture[7].rect_d.h = 85;
	env->texture[7].angle = 0;
	env->texture[7].center = 0;

		// baguettes
	env->texture[8].rect_s.x = 40;
	env->texture[8].rect_s.y = 0;
	env->texture[8].rect_s.w = 564;
	env->texture[8].rect_s.h = 1168;
	env->texture[8].rect_d.x = 350;
	env->texture[8].rect_d.y = 540;
	env->texture[8].rect_d.w = 30;
	env->texture[8].rect_d.h = 85;
	env->texture[8].angle = 70;
	env->texture[8].center = 0;


	env->texture[9].rect_s.x = 40;
	env->texture[9].rect_s.y = 0;
	env->texture[9].rect_s.w = 564;
	env->texture[9].rect_s.h = 1168;
	env->texture[9].rect_d.x = 360;
	env->texture[9].rect_d.y = 470;
	env->texture[9].rect_d.w = 30;
	env->texture[9].rect_d.h = 85;
	env->texture[9].angle = 90;
	env->texture[9].center = 0;

	env->texture[10].rect_s.x = 40;
	env->texture[10].rect_s.y = 0;
	env->texture[10].rect_s.w = 564;
	env->texture[10].rect_s.h = 1168;
	env->texture[10].rect_d.x = 490;
	env->texture[10].rect_d.y = 420;
	env->texture[10].rect_d.w = 30;
	env->texture[10].rect_d.h = 85;
	env->texture[10].angle = 120;
	env->texture[10].center = 0;

	env->texture[11].rect_s.x = 40;
	env->texture[11].rect_s.y = 0;
	env->texture[11].rect_s.w = 564;
	env->texture[11].rect_s.h = 1168;
	env->texture[11].rect_d.x = 620;
	env->texture[11].rect_d.y = 420;
	env->texture[11].rect_d.w = 30;
	env->texture[11].rect_d.h = 85;
	env->texture[11].angle = 180;
	env->texture[11].center = 0;

	env->texture[12].rect_s.x = 40;
	env->texture[12].rect_s.y = 0;
	env->texture[12].rect_s.w = 564;
	env->texture[12].rect_s.h = 1168;
	env->texture[12].rect_d.x = 780;
	env->texture[12].rect_d.y = 430;
	env->texture[12].rect_d.w = 30;
	env->texture[12].rect_d.h = 85;
	env->texture[12].angle = 240;
	env->texture[12].center = 0;

	env->texture[13].rect_s.x = 40;
	env->texture[13].rect_s.y = 0;
	env->texture[13].rect_s.w = 564;
	env->texture[13].rect_s.h = 1168;
	env->texture[13].rect_d.x = 940;
	env->texture[13].rect_d.y = 460;
	env->texture[13].rect_d.w = 30;
	env->texture[13].rect_d.h = 85;
	env->texture[13].angle = 270;
	env->texture[13].center = 0;

	env->texture[14].rect_s.x = 40;
	env->texture[14].rect_s.y = 0;
	env->texture[14].rect_s.w = 564;
	env->texture[14].rect_s.h = 1168;
	env->texture[14].rect_d.x = 940;
	env->texture[14].rect_d.y = 540;
	env->texture[14].rect_d.w = 30;
	env->texture[14].rect_d.h = 85;
	env->texture[14].angle = 285;
	env->texture[14].center = 0;
	return (NONE);
}



t_err	philo_init_baguette(t_env *env)
{
	(void)env;
	SDL_Surface *bitmapSurface[7] = {0};

	if (!(bitmapSurface[0] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[8].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[0])))

	SDL_FreeSurface(bitmapSurface[0]);

	if (!(bitmapSurface[1] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[9].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[1])))
	SDL_FreeSurface(bitmapSurface[1]);

	if (!(bitmapSurface[2] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[10].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[2])))

	SDL_FreeSurface(bitmapSurface[2]);

	if (!(bitmapSurface[3] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[11].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[3])))
	SDL_FreeSurface(bitmapSurface[3]);

	if (!(bitmapSurface[4] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[12].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[4])))
	SDL_FreeSurface(bitmapSurface[4]);

	if (!(bitmapSurface[5] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[13].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[5])))
	SDL_FreeSurface(bitmapSurface[5]);

	if (!(bitmapSurface[6] = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	if (!(env->texture[14].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface[6])))
	SDL_FreeSurface(bitmapSurface[6]);
	return (NONE);
}
