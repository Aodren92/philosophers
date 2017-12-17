#include "philosophers.h"

#define DEBUG_POS_NORM 0
#define DEBUG_POS_RIGHT 7
#define DEBUG_POS_LEFT 14

void	philo_display_baguettes(t_env *e)
{
	unsigned int	i;
	unsigned int	pos;
	t_philosphers	*philo;

	i = 8;
	philo = e->philosophers;
	while (i < 15)
	{
		if (!pthread_mutex_lock(&philo[i - 8].baguette.mutex_baguette))
		{
			pos = philo[i - 8].baguette.pos;
			SDL_RenderCopyEx(e->sys.renderer, e->texture[i].tex,
							 &e->texture[i].rect_s, &e->pos[i + pos].rect_d,
							 e->pos[i + pos].angle, e->pos[i + pos].center, 0);
			pthread_mutex_unlock(&philo[i - 8].baguette.mutex_baguette);
		}
		i++;
	}
}
