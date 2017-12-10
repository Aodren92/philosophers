#include "philosophers.h"
#include <time.h>
#include <stdio.h>
#define SECONDE 1000000
#include <stdlib.h>

/*
** routine for each philo
*/

void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (1)
	{
		take_is_own_baguette(philo);
		philo_take_right_baguette(philo);
		philo_eat(philo);
	}
	exit(EXIT_SUCCESS);
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
	return (NONE);
}

t_err	philo_join_thread(t_philosphers *philo)
{
	unsigned int	i;

	i = 0;
	while (i < 7)
	{
		philo[i].hp = -1;
		if (pthread_join(philo[i].thread, 0))
			return (E_THREAD_JOIN);
		++i;
	}
	return (NONE);
}
