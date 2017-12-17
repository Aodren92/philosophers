#include "libft.h"
#include "philosophers.h"

/*
** \XXX init func
*/

static void		sub_init(t_env *env)
{
	philo_init_philosophers(env);
	philo_init_rect(env);
	philo_init_pos(env->pos);
}

int				main(void)
{
	t_env env;
	t_err err;

	ft_bzero(&env, sizeof(t_env));
	philo_init_system(&env.sys);
	if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init())
		return (philo_error(&env, E_INIT));
	if ((err = philo_init_env(&env)))
		return (philo_error(&env, err));
	if ((err = philo_add_baguettes(&env)))
		return (philo_error(&env, err));
	if ((err = philo_init_display(&env)))
		return (philo_error(&env, err));
	if ((err = philo_init_text(&env)))
		return (philo_error(&env, err));
	if ((err = philo_init_start(&env)))
		return (philo_error(&env, err));
	sub_init(&env);
	if (!philo_main_loop(&env))
	{
		TTF_Quit();
		SDL_Quit();
	}
	philo_join_thread(env.philosophers);
	return (NONE);
}
