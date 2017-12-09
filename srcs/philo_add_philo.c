#include "philosophers.h"

static t_err	philo_add_philo(t_env *env, char *path, int philo)
{
	SDL_Surface *bitmapSurface;

	if (!(bitmapSurface = SDL_LoadBMP(path)))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface,
			SDL_TRUE, SDL_MapRGB(bitmapSurface->format, 0, 255, 0));
	if (!(env->texture[philo].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
	SDL_FreeSurface(bitmapSurface);
	return (NONE);
}


t_err			philo_add_philos(t_env *env)
{
	int	ret;

	ret = NONE;
	ret |= philo_add_philo(env, "./res/trump.bmp", 1);
	ret |= philo_add_philo(env, "./res/poutin2.bmp", 2);
	ret |= philo_add_philo(env, "./res/ben_laden.bmp", 3);
	ret |= philo_add_philo(env, "./res/syler.bmp", 4);
	ret |= philo_add_philo(env, "./res/kim.bmp", 5);
	ret |= philo_add_philo(env, "./res/bush.bmp", 6);
	ret |= philo_add_philo(env, "./res/sarko.bmp", 7);
	return (ret);
}
