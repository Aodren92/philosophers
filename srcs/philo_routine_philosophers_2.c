#include "philosophers.h"

int		philo_take_his_own_baguette(t_philosphers *philo)
{
	int ret;

	ret = 1;
	if (!pthread_mutex_trylock(&philo->baguette.mutex_baguette))
	{
		if (philo->baguette.pos == POS_BAGUETTE_NOR)
		{
			philo->state = STATE_PHILO_THINK;
			philo->timeout = THINK_T;
			philo->baguette.pos = POS_BAGUETTE_LEFT;
			ret = 0;
		}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (ret);
}

int		philo_take_right_baguette(t_philosphers *philo)
{
	int ret;

	ret = 1;
	pthread_mutex_lock(&philo->baguette.mutex_baguette);
	pthread_mutex_lock(&philo->right->mutex_state);
	if (philo->right->state != STATE_PHILO_EAT)
	{
		pthread_mutex_lock(&philo->right->baguette.mutex_baguette);
		philo->state = STATE_PHILO_EAT;
		philo->right->state = STATE_PHILO_REST;
		philo->timeout = EAT_T;
		philo->right->baguette.pos = POS_BAGUETTE_RIGHT;
		pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
		ret = 0;
	}
	pthread_mutex_unlock(&philo->right->mutex_state);
	pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	return (ret);
}

int		philo_take_rest(t_philosphers *philo)
{
	pthread_mutex_lock(&philo->baguette.mutex_baguette);
	pthread_mutex_lock(&philo->right->baguette.mutex_baguette);
	philo->state = STATE_PHILO_REST;
	philo->timeout = REST_T;
	philo->baguette.pos = POS_BAGUETTE_NOR;
	philo->right->baguette.pos = POS_BAGUETTE_NOR;
	pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
	pthread_mutex_unlock(&philo->baguette.mutex_baguette);
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
