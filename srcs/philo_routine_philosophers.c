#include "philosophers.h"

void	philo_regen_hp(t_philosphers *philo)
{
	pthread_mutex_lock(&philo->mutex_hp);
	philo->hp = MAX_LIFE;
	pthread_mutex_unlock(&philo->mutex_hp);
}

void	*philo_routine_philosophers(void *arg)
{
	t_philosphers	*philo;
	char			action;

	action = 0;
	philo = (t_philosphers *)arg;
	while (philo->running)
	{
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
				if (philo->state == STATE_PHILO_REST)
				{
					action = philo_take_his_own_baguette(philo);
				}
				else if (philo->state == STATE_PHILO_THINK)
				{
					pthread_mutex_lock(&philo->right->mutex_hp);
					if (philo->right->hp >= MAX_LIFE - 2)
					{
						pthread_mutex_unlock(&philo->right->mutex_hp);
						if (!(action = philo_take_right_baguette(philo)))
							philo_regen_hp(philo);
					}
					else
						pthread_mutex_unlock(&philo->right->mutex_hp);
				}
				else if (philo->state == STATE_PHILO_EAT)
				{
					action = philo_take_rest(philo);
				}
				pthread_mutex_unlock(&philo->mutex_state);
			}
		}
	}
	return (0);
}
