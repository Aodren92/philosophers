#include "philosophers.h"

void	philo_init_system(t_system *sys)
{
	sys->win = 0;
	sys->renderer = 0;
	sys->bitmaptex = 0;
}

t_err	philo_init_env(t_env *e)
{
	e->win.width = 1280;
	e->win.height = 720;
	//fractol_reset_view(&(e->var));
	if ((e->sys.win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win.width, e->win.height,
			SDL_WINDOW_RESIZABLE)) == NULL)
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
	SDL_Surface *bitmapSurface = NULL;

	if (!(bitmapSurface = SDL_LoadBMP("./res/background.bmp")))
		return (E_TEXTURE);
	env->sys.bitmaptex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface);
	if (!(env->sys.bitmaptex))
		return (E_INIT);
	SDL_FreeSurface(bitmapSurface);
	return (NONE);
}
