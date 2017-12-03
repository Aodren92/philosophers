#include "philosophers.h"
#include <time.h>
#include <stdio.h>
#define SECONDE 1000000
/*
** routine for each philo
*/
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (philo->hp > 0)
	{
		(void)philo->hp;	
		if (philo->hp < 55)
		{
//			pthread_mutex_lock (&mutex);

//			pthread_mutex_unlock (&mutex);
			ft_putstr("Something...\n");
			philo->baguette.pos = POS_BAGUETTE_LEFT;
		}
		philo->hp--;
		usleep(SECONDE);
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
