#include "philosophers.h"

int		get_state_philo_left(t_philosphers *philo)
{
	int state;

	if (pthread_mutex_trylock(&philo->mutex_left))
	{
		state = philo->left->state;
		pthread_mutex_unlock(&philo->mutex_left);
		if (state == STATE_PHILO_EAT)
			return (0);
		return (1);
	}
	return (0);
}

int		get_state_philo_right(t_philosphers *philo)
{
	int state;

	if (pthread_mutex_trylock(&philo->mutex_right))
	{
		state = philo->right->state;
		pthread_mutex_unlock(&philo->mutex_right);
		if (state == STATE_PHILO_EAT)
			return (0);
		return (1);
	}
	return (0);
}

/*
** call when is rest
*/

int		take_is_own_baguette(t_philosphers *philo)
{
	if (pthread_mutex_trylock(&philo->mutex_hp))
	{
		philo->state = STATE_PHILO_THINK;
		philo->timeout = THINK_T;
		philo->baguette.pos = POS_BAGUETTE_LEFT;
		pthread_mutex_unlock(&philo->mutex_hp);
		return (1);
	}
	return (0);
}

/*
** call when is thinking
*/

int		philo_take_right_baguette(t_philosphers *philo)
{
	int state;

	if ((state = get_state_philo_right(philo)))
	{
		if (pthread_mutex_trylock(&philo->mutex_b_right))
		{
			philo->state = STATE_PHILO_EAT;
			philo->timeout = EAT_T;
			philo->right->state = STATE_PHILO_REST;
			philo->right->timeout = REST_T;
			philo->right->baguette.pos = POS_BAGUETTE_RIGHT;
			pthread_mutex_unlock(&philo->mutex_b_right);
			return (1);
		}
	}
	return (0);
}

int		philo_eat(t_philosphers *philo)
{
	if (pthread_mutex_trylock(&philo->mutex_eat))
	{
		philo->hp = MAX_LIFE;
		philo->state = STATE_PHILO_REST;
		philo->timeout = REST_T;
		pthread_mutex_unlock(&philo->mutex_b_right);
		return (1);
	}
	return (0);
}
