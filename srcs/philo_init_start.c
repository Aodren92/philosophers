#include "philosophers.h"

static void	philo_init_color_start(SDL_Color *color)
{
	color->r = 50;
	color->g = 255;
	color->b = 120;
	color->a = 255;
}

t_err		philo_init_start(t_env *env)
{
	unsigned int	i;
	SDL_Surface		*surface;
	SDL_Color		textcolor;

	i = 0;
	philo_init_color_start(&textcolor);
	if (!(surface = TTF_RenderText_Solid(env->sys.font_start,
		"PhiLoSoPHerS", textcolor)))
		return (E_INIT);
	if (!(env->start[0].tex =
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return (E_INIT);
	SDL_FreeSurface(surface);
	if (!(surface = TTF_RenderText_Solid(env->sys.font_start,
		"Press Start", textcolor)))
		return (E_INIT);
	if (!(env->start[1].tex =
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return (E_INIT);
	SDL_FreeSurface(surface);
	env->start[1].rect_d.x = 550;
	env->start[1].rect_d.y = 550;
	env->start[1].rect_d.h = 100;
	env->start[1].rect_d.w = 150;
	return (NONE);
}
