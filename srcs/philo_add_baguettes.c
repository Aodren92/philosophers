#include "philosophers.h"

t_err	philo_add_baguettes(t_env *env)
{
	SDL_Surface		*bitmapsurface;
	unsigned int	i;

	if (!(bitmapsurface = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapsurface,
			SDL_TRUE, SDL_MapRGB(bitmapsurface->format, 255, 255, 255));
	i = 8;
	while (i < 15)
	{
		if (!(env->texture[i].tex = SDL_CreateTextureFromSurface(
						env->sys.renderer, bitmapsurface)))
			return (E_TEXTURE);
		++i;
	}
	SDL_FreeSurface(bitmapsurface);
	return (NONE);
}
