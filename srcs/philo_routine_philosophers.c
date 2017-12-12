#include "philosophers.h"
#define SECONDE 1000000

/*
** routine for each philo
*/

void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (philo->hp > 0 && philo->running)
	{
		take_is_own_baguette(philo);
		philo_take_right_baguette(philo);
		philo_eat(philo);
		usleep(SECONDE);
		if (philo->timeout > 0)
			philo->timeout -= 1;
		if (philo->state != STATE_PHILO_EAT)
			philo->hp -= DAMAGE_PER_S;
	}
	return (0);
}

t_err	philo_start_routine(t_env *env)
{
	unsigned int i;

	i = 0;
	env->state = 1;
	while (i < 7)
	{
		if (pthread_create(&env->philosophers[i].thread, 0,
					philo_routine_philosophers, &env->philosophers[i]))
			return (E_THREAD_CREATE);
		++i;
	}
	env->end = time(NULL) + TIMEOUT;
	return (NONE);
}

t_err	philo_join_thread(t_philosphers *philo)
{
	unsigned int	i;

	i = 0;
	while (i < 7)
	{
		philo[i].running = STOPPED;
		if (pthread_join(philo[i].thread, 0))
			return (E_THREAD_JOIN);
		++i;
	}
	return (NONE);
}
