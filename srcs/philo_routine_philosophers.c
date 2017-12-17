#include "philosophers.h"
#define SECONDE 1000000

int		philo_take_his_own_baguette(t_philosphers *philo)
{
	int ret;
	/**
	 * lock his own baguette
	 * */
	ret = 1;
	//if (!pthread_mutex_trylock(&philo->baguette.mutex_baguette))
	if (!pthread_mutex_lock(&philo->baguette.mutex_baguette))
	{
		//if (!pthread_mutex_trylock(&philo->right->mutex_state))
	//	{
			/**
			 * check pos of the baguette ,if pos normal -> ok
			 * */
			if (philo->baguette.pos == POS_BAGUETTE_NOR)
			{
				philo->state = STATE_PHILO_THINK;
				philo->timeout = THINK_T;
				philo->baguette.pos = POS_BAGUETTE_LEFT;
				ret = 0;
			}
	//		pthread_mutex_unlock(&philo->right->mutex_state);
	//	}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (ret);
}

//void	philo

#if 1
int		philo_take_right_baguette(t_philosphers *philo)
{
	int ret;

	ret = 1;
	/**
	 * need to lock his own baguette first
	 * */
	if (!pthread_mutex_lock(&philo->baguette.mutex_baguette))
	{
		/**
		 * lock the state of the right
		 * */
		if (!pthread_mutex_trylock(&philo->right->mutex_state))
		{
#if 1
			if (philo->right->state != STATE_PHILO_EAT)
			{
				/**
				 * lock his baguette
				 * */
				if (!pthread_mutex_trylock(&philo->right->baguette.mutex_baguette))
				{
					philo->state = STATE_PHILO_EAT;
					philo->right->state = STATE_PHILO_REST;
					philo->timeout = EAT_T;
					philo->right->baguette.pos = POS_BAGUETTE_RIGHT;
					ret = 0;
					pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
				}
			}
#endif
			pthread_mutex_unlock(&philo->right->mutex_state);
		}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (ret);
}
#endif


int		philo_take_rest(t_philosphers *philo)
{
	int		ret;

	ret = 1;
	/**
	 * need to lock baguettes + his own state(already locked)
	 * */
	if (!pthread_mutex_lock(&philo->baguette.mutex_baguette))
	{
		if (!pthread_mutex_lock(&philo->right->baguette.mutex_baguette))
		{
			philo->state = STATE_PHILO_REST;
			philo->timeout = REST_T;
			philo->baguette.pos = POS_BAGUETTE_NOR;
			philo->right->baguette.pos = POS_BAGUETTE_NOR;
			pthread_mutex_unlock(&philo->right->baguette.mutex_baguette);
			ret = 0;
		}
		pthread_mutex_unlock(&philo->baguette.mutex_baguette);
	}
	return (ret);
}
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
					action = philo_take_right_baguette(philo);
				}
				else if (philo->state == STATE_PHILO_EAT)
				{
					action = philo_take_rest(philo);
				}
				//	action = 0;
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
