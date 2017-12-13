#include "philosophers.h"

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
