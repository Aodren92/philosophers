#include "philosophers.h"

t_err	philo_add_baguettes(t_env *env)
{
	SDL_Surface *bitmapSurface;

	if (!(bitmapSurface = SDL_LoadBMP("./res/baguette_rouge.bmp")))
		return (E_TEXTURE);
	SDL_SetColorKey(bitmapSurface,
			SDL_TRUE, SDL_MapRGB(bitmapSurface->format, 255, 255, 255));

	if (!(env->texture[8].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[9].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[10].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[11].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[12].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[13].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	if (!(env->texture[14].tex = SDL_CreateTextureFromSurface(env->sys.renderer,
		bitmapSurface)))
		return (E_TEXTURE);
	SDL_FreeSurface(bitmapSurface);
	return (NONE);
}
