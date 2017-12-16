#include "philosophers.h"

static void		philo_init_victory(t_env *env, char *display)
{
	ft_strcat(display, "AND NOW IT'S TIME TO DANCE !!!!");
	env->text_conclusion.sdl_color.r = 0;
	env->text_conclusion.sdl_color.g = 0;
	env->text_conclusion.sdl_color.b = 255;
	env->text_conclusion.sdl_color.a = 0;
	env->text_conclusion.rect_d.x = 260;
	env->text_conclusion.rect_d.y = 300;
	env->text_conclusion.rect_d.h = 200;
	env->text_conclusion.rect_d.w = 780;
	env->text_conclusion.rect_s.x = 260;
	env->text_conclusion.rect_s.y = 300;
	env->text_conclusion.rect_s.h = 200;
	env->text_conclusion.rect_s.w = 780;
}

static void		philo_init_defeat(t_env *env, char *display)
{
	ft_strcat(display, "GAMEOVER");
	env->text_conclusion.sdl_color.r = 255;
	env->text_conclusion.sdl_color.g = 0;
	env->text_conclusion.sdl_color.b = 0;
	env->text_conclusion.sdl_color.a = 0;
	env->text_conclusion.rect_d.x = 240;
	env->text_conclusion.rect_d.y = 300;
	env->text_conclusion.rect_d.h = 200;
	env->text_conclusion.rect_d.w = 780;
	env->text_conclusion.rect_s.x = 240;
	env->text_conclusion.rect_s.y = 300;
	env->text_conclusion.rect_s.h = 200;
	env->text_conclusion.rect_s.w = 780;
}

void			philo_display_conclusion(t_env *env)
{
	char			display[1024];
	SDL_Surface		*surface;

	ft_bzero(display, 1024);
	if (env->victory == ALIVE)
		philo_init_victory(env, display);
	else
		philo_init_defeat(env, display);
	if (!(surface = TTF_RenderText_Solid(env->sys.font, display,
			env->text_conclusion.sdl_color)))
		return ;
	if (env->text_conclusion.tex)
		SDL_DestroyTexture(env->text_conclusion.tex);
	if (!(env->text_conclusion.tex =
			SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return ;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(env->sys.renderer, env->text_conclusion.tex, 0,
		&env->text_conclusion.rect_d);
}
