#include "philosophers.h"
#include <time.h>
#include <stdio.h>
#define SECONDE 1000000
/*
** routine for each philo
*/


static void	philo_change_state(t_philosphers *philo)
{
	if (!pthread_mutex_lock(&philo->mutex_state))
	{
		if (philo->state != STATE_PHILO_REST)
		{
			philo->nbr_state -= 1;
			if (philo->nbr_state == 0)
			{
				philo->baguette.pos = POS_BAGUETTE_NOR;				
				if (philo->state == STATE_PHILO_EAT)
					philo->right->baguette.pos = POS_BAGUETTE_NOR;
				philo->state = STATE_PHILO_REST;
			}
		}
		pthread_mutex_unlock(&philo->mutex_state);
	}
}

void	*philo_routine_philosophers(void *arg)
{
	t_philosphers *philo;

	philo = (t_philosphers *)arg;
	while (philo->hp > 0)
	{
		(void)philo->hp;	
		if (philo->hp < 55 && philo->state == STATE_PHILO_REST)
			take_is_own_baguette(philo);
		/*
		else if (philo->state == STATE_PHILO_THINK)
			philo_take_right_baguette(philo);
			*/
		philo_change_state(philo);
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
