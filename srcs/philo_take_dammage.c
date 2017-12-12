#include "philosophers.h"

void	philo_take_damage(t_philosphers *philo)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
//		if (philo[i].timeout > 0)
//			philo[i].timeout -= 1;
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
