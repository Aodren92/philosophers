#include "philosophers.h"

/*
** call when is rest
*/

#if 0
int		take_is_own_baguette(t_philosphers *philo)
{
	if (!pthread_mutex_trylock(&philo->baguette.mutex_baguette))
	{
		if (philo->state == STATE_PHILO_REST && philo->timeout <= 0)
		{
			if (!pthread_mutex_trylock(&philo->right->baguette.mutex_baguette))
			{
				if (philo->right->state != STATE_PHILO_EAT)
				{
					philo->state = STATE_PHILO_THINK;
					philo->timeout = THINK_T;
					philo->baguette.pos = POS_BAGUETTE_LEFT;
				}
				pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
			}
		}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (0);
}

/*
** call when is thinking
*/

int		philo_take_right_baguette(t_philosphers *philo)
{
	if (!pthread_mutex_trylock(&philo->right->baguette.mutex_baguette))
	{
		if (!pthread_mutex_trylock(&philo->baguette.mutex_baguette))
		{
			if (philo->state == STATE_PHILO_THINK && philo->right->state !=
					STATE_PHILO_EAT && philo->timeout <= 0)
			{
				philo->hp = MAX_LIFE;
				philo->state = STATE_PHILO_EAT;
				philo->timeout = EAT_T;
				philo->right->baguette.pos = POS_BAGUETTE_RIGHT;
				if (philo->right->state == STATE_PHILO_THINK)
				{
					philo->right->state = STATE_PHILO_REST;
					philo->right->timeout = REST_T;
				}
				pthread_mutex_unlock(&philo->baguette.mutex_baguette);
				return (1);
			}
			else
				pthread_mutex_unlock(&philo->baguette.mutex_baguette);
		}
		pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
	}
	return (0);
}

int		philo_eat(t_philosphers *philo)
{
	if (!pthread_mutex_trylock(&philo->baguette.mutex_baguette))
	{
		if (philo->state == STATE_PHILO_EAT && philo->timeout <= 0)
		{
			philo->state = STATE_PHILO_REST;
			philo->timeout = REST_T;
			philo->right->baguette.pos = POS_BAGUETTE_NOR;
			philo->baguette.pos = POS_BAGUETTE_NOR;
			pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
		}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (0);
}
#endif
