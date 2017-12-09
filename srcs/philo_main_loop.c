#include "philosophers.h"
#include <time.h>

#define SECONDE 1000000
t_err			philo_main_loop(t_env *e)
{
	char	run = 1;
	t_err	err = NONE;
	size_t	timer = TIMEOUT;	
	char next_flag = 1;

	(void)err;
	philo_start_routine(e);
	while (run)
	{
		printf("TIMER: %zu\n", timer);
		while (SDL_PollEvent(&e->sys.ev) || next_flag)
		{
			if (e->sys.ev.type == SDL_QUIT)
			{
				//\XXX KILL THREADS
				return (philo_exit(e, NONE));
			}
			else if (e->sys.ev.type == SDL_KEYDOWN)
			{
				if (e->sys.ev.key.keysym.sym == SDLK_ESCAPE)
				{
					//\XXX KILL THREADS
					return (philo_exit(e, NONE));
				}
				if (e->sys.ev.key.keysym.sym == SDLK_SPACE)
					next_flag = 0;
			}
		}
		SDL_RenderClear(e->sys.renderer);
		SDL_RenderCopy(e->sys.renderer, e->texture[0].tex, NULL, NULL);
		philo_display_philosophers(e);
		philo_display_baguettes(e);
		SDL_RenderPresent(e->sys.renderer);
//		usleep(SECONDE);
		philo_take_damage(e->philosophers);
	//	usleep(1);
//		philo_display_philo_console(e->philosophers);
		puts("MEH1");
		if (philo_is_dead(e->philosophers) == DEAD)
		{
			puts("GAME OVER");
			break ;
		}
		puts("MEH2");
		timer--;
		if (!timer)
		{
			puts("AND NOW IT'S TIME TO DANCE!!!!!!'");
			break ;
		}
		puts("MEH3");
		next_flag = 1;
	}
	puts("MEH4");
	return (err);
}
