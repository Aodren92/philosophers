#include "philosophers.h"

/*
** philo_exit : exit the main loop, clear run to exit while(run)
*/
t_err		philo_exit(t_env *env, t_err err)
{
	if (err)
		philo_error(env, err);
	return (err);
}
