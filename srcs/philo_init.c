#include "philosophers.h"

void	philo_init_system(t_system *sys)
{
	sys->win = 0;
	sys->renderer = 0;
}

t_err	philo_init_env(t_env *e)
{
	e->win.width = 500;
	e->win.height = 500;
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
