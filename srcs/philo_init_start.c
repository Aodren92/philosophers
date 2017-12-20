#include "philosophers.h"

static void	philo_init_color_start(SDL_Color *color)
{
	color->r = 50;
	color->g = 255;
	color->b = 120;
	color->a = 255;
}

static void	philo_init_pos_timeout(t_info_philo *timeout)
{
	timeout->rect_d.x = 960;
	timeout->rect_d.y = 55;
	timeout->rect_d.h = 60;
	timeout->rect_d.w = 150;
	timeout->rect_s.x = 960;
	timeout->rect_s.y = 55;
	timeout->rect_s.h = 60;
	timeout->rect_s.w = 150;
}

t_err		philo_init_start(t_env *env)
{
	SDL_Surface		*surface;
	SDL_Color		textcolor;

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
	philo_init_pos_timeout(&env->text_timeout);
	env->start[1].rect_d.x = 550;
	env->start[1].rect_d.y = 550;
	env->start[1].rect_d.h = 100;
	env->start[1].rect_d.w = 150;
	return (NONE);
}
