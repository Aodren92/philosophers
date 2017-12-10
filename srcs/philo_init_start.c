#include "philosophers.h"
# define FONT "angelina.ttf"

t_err	philo_init_start(t_env *env)
{
	unsigned int i;
	SDL_Surface		*surface;
	SDL_Color		textColor = {50, 255, 120, 255};

	i = 0;
	surface = TTF_RenderText_Solid(env->sys.font, "PhiLoSoPHerS", textColor); 
	if (!surface)
		return (E_INIT);
	if (!(env->start[0].tex = 
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return (E_INIT);
	SDL_FreeSurface(surface);
	surface = TTF_RenderText_Solid(env->sys.font, "Press Start", textColor); 
	if (!surface)
		return (E_INIT);
	if (!(env->start[1].tex = 
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return (E_INIT);
	SDL_FreeSurface(surface);
	env->start[1].rect_d.x = 500;
	env->start[1].rect_d.y = 500;
	env->start[1].rect_d.h = 100;
	env->start[1].rect_d.w = 150;
	return (NONE);
}
