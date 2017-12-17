#include "philosophers.h"

void	philo_display_timeout(t_env *env)
{
	char			display[1024];
	char			*timeout;
	SDL_Surface		*surface;

	ft_bzero(display, 1024);
	if (env->display_time < 0)
		env->display_time = 0;
	if (!(timeout = ft_itoa(env->display_time)))
		return ;
	ft_strcat(display, "Timeout : ");
	ft_strcat(display, timeout);
	free(timeout);
	if (!(surface = TTF_RenderText_Solid(env->sys.font, display,
										env->text_timeout.sdl_color)))
		return ;
	if (env->text_timeout.tex)
		SDL_DestroyTexture(env->text_timeout.tex);
	if (!(env->text_timeout.tex =
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return ;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(env->sys.renderer, env->text_timeout.tex, 0,
				&env->text_timeout.rect_d);
}
