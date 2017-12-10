#include "philosophers.h"
# define FONT "angelina.ttf"

t_err	philo_init_text_name(t_env *env, int index, char *name,
		SDL_Color textColor)
{
	char	display[1024];
	char	*hp;

	hp = ft_itoa(env->philosophers->hp);
	ft_strcpy(display, name);
	ft_strcat(display, ": ");
	ft_strcat(display, hp);
	ft_strcat(display, " HP");
	free(hp);
	SDL_Surface *surface = TTF_RenderText_Solid(env->sys.font, display, textColor); 
	if (!surface)
		return (E_INIT);
	if (!(env->text[index].tex =
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
		return (E_INIT);
	SDL_FreeSurface(surface);
	return (NONE);
}

t_err	philo_init_text(t_env *env)
{
	unsigned int i = 0;

	if (!(env->sys.font = TTF_OpenFont(FONT, 600)))
		return (E_INIT);
	philo_init_color(env);
	while (i < 7)
	{
		if (philo_init_text_name(env, i, env->philosophers[i].name, 
					env->text[i].sdl_color))
		return (E_INIT);
		++i;
	}
	philo_init_pos_name(env);
	return (NONE);
}
