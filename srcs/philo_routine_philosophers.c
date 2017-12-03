#include "philosophers.h"
#include <time.h>
#include <stdio.h>
/*
** routine for each philo
*/
void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (1)
	{
		(void)arg;
		printf("Hey missis , my name is %s, and to my right i see %s,\
				tomy left is %s\n", philo->name, philo->right->name, 
				philo->left->name);
		//\XXX remove
		sleep(1);
	}
	return (0);
}

t_err	philo_start_routine(t_env *env)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
		if (pthread_create(&env->philosophers[i].thread, 0,
					philo_routine_philosophers, &env->philosophers[i]))
			return (E_THREAD_CREATE);
		++i;
	}
	return (NONE);
}
