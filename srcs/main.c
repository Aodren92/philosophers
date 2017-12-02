#include "libft.h"
#include "philosophers.h"

int		main(void)
{
	t_env env;
	t_err err;
	
	philo_init_system(&env.sys);
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		philo_error(&env, E_INIT);
		return (E_INIT);
	}
	if ((err = philo_init_env(&env)))
	{
		philo_error(&env, err);
		return (err);
	}
	if (!philo_main_loop(&env))
		SDL_Quit(); 
	return (NONE);
}
