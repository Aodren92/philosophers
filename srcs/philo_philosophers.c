#include "philosophers.h"

/**
 * return the state of the the philospoher to is 
 * right
 * philo -> index of the philo
 * */
int		get_state_right_philo(t_env *env, int philo)
{
	if (philo == 0)
		return (env->philosophers[6].state);
	else
		return (env->philosophers[philo - 1].state);
}

int		get_state_left_philo(t_env *env, int philo)
{
	if (philo == 6)
		return (env->philosophers[0].state);
	else
		return (env->philosophers[philo + 1].state);
}

int		get_sate_left_baguette(t_env *env, int philo)
{
	return (env->philosophers[philo].baguette.state);
}

int		get_state_right_baguette(t_env *env, int philo)
{
	if (philo == 0)
		return (env->philosophers[6].baguette.state);
	else
		return (env->philosophers[philo - 1].baguette.state);
}

int		take_right_baguette(t_env *env, int philo)
{

	(void)env, (void)philo;
	return 0;

}
