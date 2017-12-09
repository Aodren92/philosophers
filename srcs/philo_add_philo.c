#include "philosophers.h"

static t_err	philo_add_philo(t_env *env, char *path, int philo)
{
	SDL_Surface *bitmapsurface;

	if (!(bitmapsurface = SDL_LoadBMP(path)))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapsurface,
			SDL_TRUE, SDL_MapRGB(bitmapsurface->format, 0, 255, 0));
	if (!(env->texture[philo].tex =
				SDL_CreateTextureFromSurface(env->sys.renderer
					, bitmapsurface)))
		SDL_FreeSurface(bitmapsurface);
	return (NONE);
}

t_err			philo_add_philos(t_env *env)
{
	int				ret;
	t_philosphers	*philos;

	philos = env->philosophers;
	ret = NONE;
	ret |= philo_add_philo(env, "./res/trump.bmp", 1);
	ft_strcpy(philos[1].name, "Trump");
	ret |= philo_add_philo(env, "./res/poutin2.bmp", 2);
	ft_strcpy(philos[1].name, "Poutin");
	ret |= philo_add_philo(env, "./res/ben_laden.bmp", 3);
	ft_strcpy(philos[1].name, "Ben Laden");
	ret |= philo_add_philo(env, "./res/syler.bmp", 4);
	ft_strcpy(philos[1].name, "Stalone");
	ret |= philo_add_philo(env, "./res/kim.bmp", 5);
	ft_strcpy(philos[1].name, "Kim");
	ret |= philo_add_philo(env, "./res/bush.bmp", 6);
	ft_strcpy(philos[1].name, "Bush");
	ret |= philo_add_philo(env, "./res/sarko.bmp", 7);
	ft_strcpy(philos[1].name, "Sarko");
	return (ret);
}
