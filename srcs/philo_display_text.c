#include "philosophers.h"

void	philo_display_text(t_env *env)
{
	unsigned int i = 0;

	while (i < 7)
	{
		if (philo_init_text_name(env, i, env->philosophers[i].name,
					env->text[i].sdl_color))
			return ;
		++i;
	}
	i = 0;
	while (i < 7)
	{
		SDL_RenderCopy(env->sys.renderer, env->text[i].tex, 0,
		   	&env->text[i].rect_d);
		++i;
	}
}
