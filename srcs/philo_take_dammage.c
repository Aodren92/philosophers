#include "philosophers.h"

void	philo_change_state(t_philosphers *philo)
{
	if (philo->timeout == 0)
	{
		if (philo->state != STATE_PHILO_REST)
		{
			philo->timeout = REST_T;
			philo->state = STATE_PHILO_REST;
			philo->baguette.pos = POS_BAGUETTE_NOR;
		}
	}
}

void	philo_take_damage(t_philosphers *philo)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
		if (philo[i].timeout > 0)
			philo[i].timeout -= 1;
		philo_change_state(&philo[i]);
		if (philo[i].state != STATE_PHILO_EAT)
			philo[i].hp -= DAMAGE_PER_S;
		++i;
	}
}

int		philo_is_dead(t_philosphers *philo)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
		if (philo->hp <= 0)
			return (DEAD);
		++i;
	}
	return (ALIVE);
}
