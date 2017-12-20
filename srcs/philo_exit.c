#include "philosophers.h"

/*
** philo_exit : exit the main loop, clear run to exit while(run)
*/

static void		philo_cleanup_2(t_env *env)
{
	if (env->text_timeout.tex)
		SDL_DestroyTexture(env->text_timeout.tex);
	if (env->text_conclusion.tex)
		SDL_DestroyTexture(env->text_conclusion.tex);
	if (env->start[0].tex)
		SDL_DestroyTexture(env->start[0].tex);
	if (env->start[1].tex)
		SDL_DestroyTexture(env->start[1].tex);
	if (env->sys.renderer)
		SDL_DestroyRenderer(env->sys.renderer);
	if (env->sys.win)
		SDL_DestroyWindow(env->sys.win);
}

static void		philo_cleanup(t_env *env)
{
	size_t	i;

	i = 0;
	if (i < NBR_TEXTURES)
	{
		if (env->texture[i].tex)
			SDL_DestroyTexture(env->texture[i].tex);
	}
	i = 0;
	if (i < 7)
	{
		if (env->text[i].tex)
			SDL_DestroyTexture(env->text[i].tex);
	}
	philo_cleanup_2(env);
}

t_err			philo_exit(t_env *env, t_err err)
{
	if (err)
		philo_error(env, err);
	philo_cleanup(env);
	TTF_CloseFont(env->sys.font);
	TTF_CloseFont(env->sys.font_start);
	TTF_Quit();
	SDL_Quit();
	philo_join_thread(env->philosophers);
	return (err);
}

t_err			philo_exit_gfx(t_env *env, t_err err)
{
	if (err)
		philo_error(env, err);
	philo_cleanup(env);
	TTF_CloseFont(env->sys.font);
	TTF_CloseFont(env->sys.font_start);
	TTF_Quit();
	SDL_Quit();
	return (err);
}
