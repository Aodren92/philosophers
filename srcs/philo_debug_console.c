#include "philosophers.h"
#include <stdio.h>

static void	philo_display_baguette(t_baguette bag)
{
	printf("BAGUETTE : \n");
	if (bag.pos == POS_BAGUETTE_NOR)
		printf("baguette sur la table \n");
	if (bag.pos == POS_BAGUETTE_LEFT)
		printf("baguette sur la gauche (propre philo) \n");
	if (bag.pos == POS_BAGUETTE_RIGHT)
		printf("baguette sur la droite (voler) \n");
}

void		philo_display_philo_console(t_philosphers *philo)
{
	unsigned int i;

	i = 0;
	while (i < 7)
	{
		if (pthread_mutex_trylock(&philo->mutex_hp))
		{
			printf("/------------------------------------------\\\n");
			printf("Philosohpers : %s\n", philo[i].name);
			printf("HP: %d\n", philo[i].hp);
			printf("timeout: %d\n", philo[i].timeout);
			if (philo[i].state == STATE_PHILO_REST)
				printf("STATE: STATE_PHILO_REST\n");
			else if (philo[i].state == STATE_PHILO_EAT)
				printf("STATE: STATE_PHILO_EAT\n");
			else if (philo[i].state == STATE_PHILO_THINK)
				printf("STATE: STATE_PHILO_THINK\n");
			philo_display_baguette(philo[i].baguette);
			printf("\\------------------------------------------/\n");
			pthread_mutex_unlock(&philo->mutex_hp);
		}
		++i;
	}
}
