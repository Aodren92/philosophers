#include "philosophers.h"

static t_err	philo_text_name_part_2(char *display, SDL_Color textcolor,
					t_env *env, int index)
{
	SDL_Surface *surface;

	surface = TTF_RenderText_Solid(env->sys.font, display, textcolor);
	if (!surface)
		return (E_INIT);
	if (env->text[index].tex)
		SDL_DestroyTexture(env->text[index].tex);
	if (!(env->text[index].tex =
				SDL_CreateTextureFromSurface(env->sys.renderer, surface)))
	{
		SDL_FreeSurface(surface);
		return (E_INIT);
	}
	SDL_FreeSurface(surface);
	return (NONE);
}

t_err			philo_init_text_name(t_env *env, int index, char *name,
					SDL_Color textcolor)
{
	char	display[1024];
	char	*hp;

	ft_bzero(display, 1024);
	hp = 0;
	if (!pthread_mutex_lock(&env->philosophers[index].mutex_hp))
	{
		hp = ft_itoa(env->philosophers[index].hp);
		pthread_mutex_unlock(&env->philosophers[index].mutex_hp);
	}
	if (!hp)
		return (NONE);
	ft_strcpy(display, name);
	ft_strcat(display, ":");
	philo_space_char(display + ft_strlen(name) + 1, env->philosophers->hp,
			19 - ft_strlen(name));
	ft_strcat(display, hp);
	ft_strcat(display, " HP");
	free(hp);
	return (philo_text_name_part_2(display, textcolor, env, index));
}

t_err			philo_init_text(t_env *env)
{
	unsigned int i;

	i = 0;
	if (!(env->sys.font = TTF_OpenFont(FONT, 1200)))
		return (E_INIT);
	if (!(env->sys.font_start = TTF_OpenFont(FONT_START, 1200)))
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
