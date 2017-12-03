#include "philosophers.h"
#include <time.h>
#include <stdio.h>
#define SECONDE 1000000
/*
** routine for each philo
*/


#if 0
static void	philo_timeout_state(t_philosphers *philo)
{
	if (!pthread_mutex_lock(&philo->mutex_state))
	{
		if (philo->timeout > 0)
			philo->timeout--;
		if (philo->timeout == 0 && philo->state != STATE_PHILO_REST)
		{
			philo->baguette.pos = POS_BAGUETTE_NOR;				
			if (philo->state == STATE_PHILO_EAT)
			{
				philo->right->baguette.pos = POS_BAGUETTE_NOR;
				philo->hp = MAX_LIFE;
			}
			philo->timeout = REST_T;
			philo->state = STATE_PHILO_REST;
		}
		pthread_mutex_unlock(&philo->mutex_state);
	}
}
#endif

#include <stdlib.h>
void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (philo->hp > 0)
	{
		(void)philo->hp;	
		if (philo->state == STATE_PHILO_REST && philo->timeout <= 0)
			take_is_own_baguette(philo);
		else if (philo->state == STATE_PHILO_THINK && philo->timeout <= 0)
			philo_take_right_baguette(philo);
		else if (philo->state == STATE_PHILO_EAT && philo->timeout <= 0)
			philo_eat(philo);
//		usleep(SECONDE);
	//	philo_timeout_state(philo);
	}
	exit(EXIT_SUCCESS);
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
