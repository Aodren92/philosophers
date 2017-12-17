#include "philosophers.h"
#define SECONDE 1000000

/*
** routine for each philo
*/

void	*philo_routine_philosophers(void *arg)
{
	t_philosphers	*philo;
	char			action = 0;


	philo = (t_philosphers *)arg;
	while (philo->running)
	{
		/*take_is_own_baguette(philo);
		philo_take_right_baguette(philo);
		philo_eat(philo);
		if (philo->timeout > 0)
			philo->timeout -= 1;
		if (philo->state != STATE_PHILO_EAT)
			philo->hp -= DAMAGE_PER_S;
		usleep(SECONDE);*/
		if (!pthread_mutex_trylock(&philo->mutex_hp))
		{
			if (philo->hp <= 0)
			{
				pthread_mutex_unlock(&philo->mutex_hp);
				break ;
			}
			pthread_mutex_unlock(&philo->mutex_hp);
		}
		if (!pthread_mutex_trylock(&philo->mutex_timeout))
		{
			if (philo->timeout <= 0)
				action = 1;
			pthread_mutex_unlock(&philo->mutex_timeout);
		}
		if (action)
		{
			if (!pthread_mutex_trylock(&philo->mutex_state))
			{
				/*
				if (philo->state = STATE_PHILO_REST)
				{
					if (!philo_eat())
						philo_think();
				}
				else if (philo->state = STATE_PHILO_THINK)
				{
					if (!philo_eat())
						philo_think();
				}
				 */
				action = 0;
				pthread_mutex_unlock(&philo->mutex_state);
			}
		}
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
